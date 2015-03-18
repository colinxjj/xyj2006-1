// fangjian2.c
// by lestat

inherit ROOM;
#include <ansi.h>

string *strs = ({
        " �������ƺ�֮ˮ����������������������  \n",
        " �����������������׷���������˿ĺ��ѩ   \n",
        " ���������뾡����Īʹ���׿ն���         \n",
        " �����Ҳı����á�ǧ��ɢʧ������         \n",
        " ������ţ��Ϊ�֣�����һ�����ٱ�      \n",
        " ᯷��ӣ��������������ƣ���Īͣ      \n",
        " �����һ�������Ϊ�Ҳ����        \n",
     });
     
void init();
void check_time(object where);
void play(object where);
void finish_play(object where);
void create()
{
        set("short", "�һ���");
        set("long", @LONG
����һ���ٷ�����˿�����ӿ�������������(play).��������ʯ
����ǽ��������һ�������٣����߶��Ѿ����ˡ�
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));

	    set("objects",([
		__DIR__"npc/niang" : 1,
		"/d/pansi/obj/qin.c":1, 
	]));
	
       set("no_clean_up", 0);
       setup();
}

void init()
{
	remove_call_out("check_time");
        check_time(this_object());
        add_action("do_play", "play");
        add_action("do_han", "han");
}
void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   
   if(phase==5&&(!query("shuilian/start_play"))) play(where);
   if(phase==6&&query("shuilian/start_play")) finish_play(where);
   call_out("check_time",60,where);
}

void play(object where)
{
     message("channel:es",CYN+"��"MAG"��˿��"CYN"��"WHT"����ʮ��[Chun sanshiniang]"CYN"�����˻��һ������٣�\n"+NOR,users());
     where->set("shuilian/start_play",1);
} 

int do_play()
{ 
     object who=this_player();
     
     if(who->is_busy())
        return notify_fail("����æ���ء�\n");
     if(!this_object()->query("shuilian/start_play"))
        return notify_fail("���������ٵ�ʱ���ء�\n");
     if((string)who->query("family/family_name")!="��˿��")
        return notify_fail("���ɵ��Ӳ����������١�\n");
//     tell_object( who,"���ü��Ŀ������΢�̣�"+strs[random( sizeof(strs) )] );
     tell_object( who,"��˫�����Ღ���ң��������������������" );
     who->start_busy(5);
     if ( (int)who->query("faith")<40000)
     who->add("faith",1);
     who->ichatrove_skill("qin",random((int)(who->query("spi")+who->query("int"))/2),1);
     who->ichatrove_skill("pansi-dafa",random((int)(who->query("spi")+who->query("int"))/2),1);
     who->add("combat_exp",12);
     who->add("potential",3);
     who->receive_damage("kee",20);
     who->receive_damage("sen",20);
     tell_object(who,"��������ս����ˣ�\n");
     return 1;
}

void finish_play(object where)
{
     tell_object(where,"�����͵�һͣ,����ʮ�ﻺ��վ���:������������\n");
     where->delete("shuilian/start_play");
}

int do_han(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="֥�鿪��") 
	{
		tell_object(me,"�����˵������ǽ�ڴ��һ������֥�鿪�ţ���\n");
		message("vision", "����һ�������ֻ����һ���¡¡��������������һ�����š�\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}

void close(object room)
{
	message("vision","һ���¡¡����������ʯ���ֻ����ع����ˡ�\n", room);
	room->delete("exits/down");
}
int valid_leave(object me,string dir)
{
        if(dir=="down" && (!me->query("family") || (me->query("family/family_name")!="�ɽ�")) && present("niang",environment(me))) 
             return notify_fail("��ʮ����һ��������ס�����ȥ·��\n");
        return ::valid_leave(me,dir);
}
