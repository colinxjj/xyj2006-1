// channeld.c
// modified by tool on 96/10/05
// modified by mon@xyj on 10/97 to add support for
//          intermud emote.

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

#define REMOTE_Q    "/adm/daemons/network/services/remote_q.c"

mapping channels = ([
	"sys":	([	"msg_speak": HIR "��ϵͳ��%s��%s\n" NOR, "wiz_only": 1 ]),
	"wiz":	([	"msg_speak": HIY "����ʦƵ����%s��%s\n" NOR,
				"msg_emote": HIY "����ʦƵ����%s\n" NOR,
				"wiz_only": 1
			]),
	"gwiz":	([	"msg_speak": HIW "��������ʦ��%s��%s\n" NOR,
				"msg_emote": HIW "��������ʦ��%s\n" NOR,
				"wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
				"filter": 1,
				"intermud_emote": 1 ]),
	"xyj":	([	"msg_speak": HIY "�����μǡ�%s��%s\n" NOR,
				"msg_emote": HIY "�����μǡ�%s\n" NOR,
				"intermud": GCHANNEL, "channel": "xyj",
				"filter": (:$1["MUDLIB"]=="��������" :) ]),
	"es":	([	"msg_speak": WHT "���������ġ�%s��%s\n" NOR,
				"msg_emote": WHT "���������ġ�%s\n" NOR,
				"intermud": GCHANNEL, "channel": "es",
				"filter": 1 ]),

        "sldh": ([      "msg_speak": HIC "��ˮ½��᡿%s��%s\n" NOR,
                                "msg_emote": HIC "��ˮ½��᡿%s\n" NOR,
                         ]),
        "jy":   ([      "msg_speak": HIC "��" HIC"������Ϣ"HIC"��%s��%s\n" NOR,
				"msg_emote": HIC "��" HIC"������Ϣ"HIC"��%s\n" NOR,
			 ]),

/*        "hxxt": ([      "msg_speak": HIC "��"HIW"��������"HIC"��%s��%s\n" NOR,
				"msg_emote": HIC "��"HIY"��������"HIC"��%s\n" NOR,
                          ]),*/
        "chat": ([      "msg_speak": HIC "��"HIW"��������"HIC"��%s��%s\n" NOR,
                                "msg_emote": HIC "��"HIY"��������"HIC"��%s\n" NOR,
			 ]),
	"rumor":([	"msg_speak": HIM "��ҥ�ԡ�%s��%s\n" NOR,
				"msg_emote": HIM "��ҥ�ԡ�%s\n" NOR,
				"anonymous": "ĳ��"
			]),
	"music":([	"msg_speak": HIM "�������ָ���%s���ţ�%s\n" NOR,
			 ]),

        "job": ([      "msg_speak": HIW "��"HIG"����"HIW"��%s��%s\n" NOR,
				"msg_emote": HIW "��"HIY"����"HIW"��%s\n" NOR,
			 ]),
]);

void create()
{
	seteuid(getuid());	// This is required to pass intermud access check.
        set("channel_id", "Ƶ������");
}

varargs int do_channel(object me, string verb, string arg, int emote,
	int allow_chat)
{
	object *ob;
	string *tuned_ch, who, arg1;
	int time,count,count1,last_chat,len;

	// Check if this is a channel emote.
        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
		emote = 1;
		verb = verb[0..<2];
	}
	
	// mon 10/29/98
	// ignore too long messages to reduce flooding.
	if(arg && strlen(arg)>240) return 0;

	if( !mapp(channels) || undefinedp(channels[verb]) )
		return 0;

	if( userp(me) && !allow_chat ) {
		if(channels[verb]["wiz_only"] && !wizardp(me) )
			return 0;
    // check if this channel support emote message. 
    if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
        write("�Բ������Ƶ����֧�� emote ��\n");
        return 1;
    }

                //temporary block chat flooding.
		time=time();
		if(me->query("channel/chat_block") &&
		  (time-me->query("channel/chat_block"))<0 )
		   return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
              
	        count=me->query("channel/chat_count");
		// if the channel arg contains too many lines,
		// then count more than once. -- mon 8/16/98
		count1=sizeof(explode(" "+arg,"\n"))/3+1;
		// if arg too long, also counts more.
		count1+=sizeof(arg)/200;
		count+=count1;
		last_chat=me->query("channel/last_chat");
		if (count>2) {
		  count=0;
		  me->set("channel/last_chat",time);
		  if (time==last_chat || count1>2) {
		    me->set("channel/chat_block",time+180);
		    return notify_fail("��Ϊһ�ν���̫�࣬��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
		  }
	        }
		me->set("channel/chat_count",count);

		if( arg==(string)me->query_temp("last_channel_msg") )
			return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");

		// If we speaks something in this channel, then must tune it in.
		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch) )
			me->set("channels", ({ verb }) );
		else if( member_array(verb, tuned_ch)==-1 )
			me->set("channels", tuned_ch + ({ verb }) );

		// Support of channel emote
		if( emote && !channels[verb]["intermud_emote"]) {
			string vb, emote_arg;

			if( nullp(arg) ) return 0;
			if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
				vb = arg;
				emote_arg = "";
			}
		if( channels[verb]["anonymous"] )
			   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
                else {
		   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
			int age=me->query("mud_age");
			// prevent login  newbie to flood channels.
			if(!wizardp(me)) {
			    if(age<3600) return notify_fail(
				    "�����ڻ�����ʹ�����Ƶ����\n");
			    else if(age<86400) {
				if((int)me->query("sen")<30) return 
				    notify_fail
					("�����ھ����㣬����ʹ�����Ƶ����\n");
				me->add("sen",-5);
			    }
			}

                REMOTE_Q->send_remote_q(site, verb, me->query("id"), id, vb);
                write("��·ѶϢ���ͳ������Ժ�\n");

                return 1;
		      }
                   }
                }

		if( !arg ) return 0;
		}
	}

	// Make the identity of speaker.

	if( channels[verb]["anonymous"] ) {
		who = channels[verb]["anonymous"];
		if (userp(me)) {
		    if((int)me->query("sen")<50) return
			notify_fail("���Ѿ�û�о���ɢ��ҥ���ˡ�\n");
		    me->add("sen",-5);
                  do_channel( this_object(), "sys", 
		    sprintf("ҥ�ԣ�%s(%s)��", me->name(1),me->query("id")));
		}
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
		who = me->query("name");
		if(me->query("id")) 
		  who=who+"(" + capitalize(me->query("id")) + ")";
             }

	// Ok, now send the message to those people listening us.

	ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
	if( !arg ) arg = "������";

	len=strlen(arg);
	while(len>1 && arg[len-1]=='\n')
	    arg=arg[0..((len--)-2)];
	//remove excessive return at the end. by mon 9/20/97

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

	if( emote ) {
		// Support of old behavier of intermud emote.
		if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;
	}

	if( arrayp(channels[verb]["extra_listener"]) ) {
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}
	
	if( !undefinedp(channels[verb]["intermud"])
	&&	base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
	    int age=me->query("mud_age");

            arg=replace_string(arg, "$N", me->name()+"("+
                capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());

	    // prevent login  newbie to flood channels.
	    if(!wizardp(me)) {
	      if(age<3600) return notify_fail(
		    "�����ڻ�����ʹ�����Ƶ����\n");
	      else if(age<86400) {
		if((int)me->query("sen")<30) return 
		    notify_fail
			("�����ھ����㣬����ʹ�����Ƶ����\n");
		me->add("sen",-5);
	      }
	    }
          }
	  channels[verb]["intermud"]->send_msg(
		channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

	if( emote ) {
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_emote"], arg1 ), ob );
	} else
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );

	if( userp(me) ) 
		me->set_temp("last_channel_msg", arg);

	return 1;
}

int filter_listener(object ppl, mapping ch)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl) ) return 0;

	if( ch["wiz_only"] ) return wizardp(ppl);
	return 1;
}

void register_relay_channel(string channel)
{
	object ob;

	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}


