
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// yushu.c, ����
// created by mes, updated 6-20-97 pickle
// updated again by pickle on 9-2-97, to open her menpai

/************************************************************/

// declarations and variables

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
   string ask_mieyao();
   string ask_cancel();
string say_key();
void punish_player(object me);
   string ask_swear();
int accept_object(object me, object ob);

/************************************************************/
void create()
{
  set_name("����", ({"yu shu","yushu", "shu", "monster"}));
    set_weight(1000000);
  set("gender", "Ů��" );
  set("age", 23);
  set("long", 
"���������޵׶��Ķ����ˡ������޵�����������������������\n"
"Ҳ��֪Ϊʲô��ʻ�δ���ɱ���Χ�ˡ���˵�����칬���ף�Ҳ\n"
"��֪��١�\n");
  set("title", "��ӿ����");
  set("combat_exp", 1500000);
  set("attitude", "heroic");
  set("daoxing", 3000000);
  create_family("�ݿ�ɽ�޵׶�", 1, "����");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set_skill("unarmed", 150);
  set_skill("dodge", 180);
  set_skill("parry", 160);
  set_skill("spells", 160); 
  set_skill("yaofa", 160);
  set_skill("sword",190);
  set_skill("qixiu-jian",190);
  set_skill("blade", 180);
  set_skill("kugu-blade", 200);
  set_skill("lingfu-steps", 150);
  set_skill("yinfeng-zhua", 150);
  set_skill("force", 180);   
  set_skill("huntian-qigong", 180);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
  set("per", 50);
  set("max_kee", 2500);
  set("max_sen", 2500);
  set("force", 3800);
  set("max_force", 2000);
  set("force_factor", 150);
  set("mana",3000);
  set("max_mana", 3000);
  set("mana_factor", 50);
  set("inquiry",([
// "����" : (: ask_mieyao :),
    "cancel" : (: ask_cancel :),
       "key": (: say_key :),
       "Կ��": (: say_key :),
       "name": "����������޵׶��Ŀ�ɽ��ʦ��",
    "����" : (: ask_swear :),
       "here": "��������ݿ�ɽ�޵׶����������ʮ�������Ҳ�κ��Ҳ��ã�",
       "rumors": "����ո�ץסһ�����С��������Ͼ�������������ˡ�",
       "�������": "���ʣ����˲���ȥ�ҳ��ӣ�",
       "����": "�ٺ٣��������������ء��������Ӹɾ��˾Ϳ��������˳��ˡ�\n"
          "����Ҳ������ȥ�������ˡ�˵�������Ѿ������ˡ�",
       "����": "Ҫ����Ҳ�У����ǲ�֪���Ұ�Կ�׷��Ķ��ˡ�",
       ]));
  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
     (: exert_function, "zhangqi" :),
        (: perform_action,"blade", "pozhan" :),
        (: perform_action,"blade", "diyu" :),
   }) );
  setup();
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
}
/**************************************************************/
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}
string ask_mieyao()
{
   object me=this_player();

    if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
      return ("�㲻�Ǳ�������!");

   command("pat "+me->query("id"));
    command("say ��־����");
   return "/d/obj/mieyao"->query_yao(me);
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if(me->query("family/master_id") != "tian shu" && me->query("combat_exp") < 200000)
  {
      command("say ʲô���������ҹ���");
      return 1;
  }
  if (me->query("wudidong/sell_reward") < me->query("combat_exp") / 20)
  {
    command("say "+myname+"Ҫ���������£��ȶ�ȥŪЩ�����������￴���ĳϣ����ʦ�ͺ������ˡ�");
    return 1;
  }
  if (me->query_skill("huntian-qigong", 1) < 50 && me->query("combat_exp") < 200000)
  {
    command("say "+me->name()+"��������ƾ�ǵ㱾�»����䣡");
    return 1;
  }
  command("grin");
  command("say ���������������ˡ�"+myname+"�����˶������Ū��ԭ�ϣ�");
  command("recruit "+myid);
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  ob->set("title", YEL"�ݿ�ɽ��ӿ�������µ���"NOR);
  }
}
/************************************************************/

// the prevent learn series... first yushu tosses the player
// if he's saved the monk, and second she has condition of
// learning kugu-blade.

int prevent_learn(object me, string skill)
{
  int mykugu=me->query_skill("kugu-blade", 1);
  if (wizardp(me) && me->query("env/immortal"))
    return 0;
  if (skill == "kugu-blade")
  {
      if (mykugu>=200)
      {
   command("say �����ò��������̣��ѵ�������ǲ����ģ�");
   return 1;
      }
      if (mykugu<200 && me->query("wudidong/given_book_3")) return 0;
      if (mykugu<141 && me->query("wudidong/given_book_2")) return 0;
      if (mykugu<=81 && me->query("wudidong/given_book_1")) return 0;
      command("say ���̣������޵׶�����֮�ܣ�");
      return 1;

    }
  if (skill == "yaofa" && me->query("obstacle/wudidong")=="done")
  {
      call_out("punish_player", 1, me);
      return 1;
  }
  return 0;
}
int accept_object(object me, object ob)
{
    int volume;
    if(ob->query("name_recognized") != "�ݹǵ�����")
        return notify_fail(CYN"����ŭ�������ʣ����ֲ��������õģ�\n"NOR);
    volume=ob->query("��");
    me->set("wudidong/given_book_"+(string)volume, 1);
    if (me->query("family/master_id") != "yu shu")
   command("say �ţ���Ȼ���������Ե�����ŵ�ԣ�����Ϊͽ��");
    command("recruit "+me->query("id"));
    if (me->query("family/master_id") == "yu shu")
   command("say ��ͽ�ܣ���Ȼ������ʦ����һ�����̡�");
    return 1;
}

void punish_player(object me)
{
    object *inv, ob;
    int i;
    inv=all_inventory(me);
    i=(int)sizeof(inv);
    while(i--)
    {
        ob=present(inv[i],me);
        destruct(ob);
        continue;
    }
    command("say "+me->name()+"������ʣ�����ȥ�úÿ�������ͺ¿���㾹�Ұ����������ˣ�");
    command("say ��ô�ĵ��ӣ����һ���������ѧ���£�");
    command("say ���úý�ѵ��ѵ�㣬���˻�����Ϊ�����Ǻ��۸����ˣ�");
    message_vision("ֻ�������������˸��������������дʣ���$N�ȵ�������\n", me);
    me->unconcious();
    message_vision("��������С��������$N������һ�ӡ�$N�����ˣ�\n", me);
    me->move("/d/qujing/wudidong/punish");
    message("vision", "ֻ�����ˡ���һ����$N����������\n", me);
    return;
}
/*********************************************************************/
string say_key()
{
  object me=this_player(), ob, npc=this_object();
  int mykar=me->query_kar();
  int real_key_condition;

  if(npc->is_fighting() || me->is_fighting())
    return ("û�ţ����ŵ㣡");
  if (member_array("tian shu",me->parse_command_id_list())==-1 )
    {
      call_out("killplayer", 1, me);
      return ("�Ķ�����"+RANK_D->query_rude(me)+"��������");
    }
  message_vision(CYN"�����$N˵�����ðɣ���ȥ����\n"NOR, me);
  if (npc->query_temp("gave_out_key"))
      real_key_condition=0;
  else real_key_condition=1;
  if (!real_key_condition)
    {
      ob=new("/d/qujing/wudidong/obj/key-fake");
    }
  else if (random(mykar)>8)
    {
      ob=new("/d/qujing/wudidong/obj/key-real");
      npc->set_temp("gave_out_key", 1);
    }
  else ob=new("/d/qujing/wudidong/obj/key-fake");
  ob->move(me);
  me->set_temp("mark/wudidong_yushu_gave_me_key", 1);
  return ("�úÿ�����ͺ¿��\n");
}
void killplayer(object me)
{
  this_object()->kill_ob(me);
}
/**************************************************************/
void init()
{
//       add_action("do_swear", "swear");
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    call_out("greeting", 1, me);
  }
}
void greeting(object me)
{
  int myspells=me->query_skill("spells");
  int mykar=me->query_kar();
  string npcname=this_object()->query("name");
  string npcrude=RANK_D->query_self_rude(this_object());
  string myrude=RANK_D->query_rude(me);

  if( !me || environment(me) != environment() ) return;
  if( me->query("family/family_name") == "�ݿ�ɽ�޵׶�")
    return;
  if( member_array("yu shu", me->parse_command_id_list())!=-1)
    {
      command("say �ĸ����ˣ����ұ��"+npcrude+"������ҡײƭ����������");
      kill_ob(me);
      return;
    }
  if( member_array("tian shu",me->parse_command_id_list())==-1 )
    {
      command("say ��������"+myrude+"���޵׶���������Ұ�ĵط�����������");
      command("kill " + me->query("id"));
      return;
    }
  if( random(mykar) > 8) return;
  else
    {
      message_vision(CYN ""+npcname+"��$N��ȵ���߾��ʲô�������������"+RANK_D->query_self_rude(this_object())+"�������ȥ��\n"NOR, me);
      message_vision(npcname+"��һ�����֣�$N��ʱ�ֳ�ԭ�Σ�ԭ����"+me->query("name")+"��\n", me);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      kill_ob(me);
      return;
    }
}



//int do_swear()
string ask_swear()
{
	object me;
	int amount,i;
	mapping skills;
	string *skillsname;
	me=this_player();
        me->command("say ��Ը��Ч�ҷ��ˣ���Զ���޵׶��ĺõ��ӡ�");
	if (mapp(skills = me->query_skills()))
            {
               skills = me->query_skills();
               skillsname = keys(skills);
               amount = sizeof(skills);
               for (i = 0; i < amount; i++)
                {if (skillsname[i]!="qixiu-jian"
                     && skillsname[i]!="kugu-blade"
                     && skillsname[i]!="yinfeng-zhua"
                     && skillsname[i]!="daya-jian"
                     && skillsname[i]!="yaofa"
                     && skillsname[i]!="huntian-qigong"
                     && skillsname[i]!="blade"
                     && skillsname[i]!="dodge"
                    && skillsname[i]!="lingfu-steps"
                     && skillsname[i]!="stealing"
                     && skillsname[i]!="sword"
                     && skillsname[i]!="parry"
                     && skillsname[i]!="unarmed"
                     && skillsname[i]!="literate"
                     && skillsname[i]!="force"
                     && skillsname[i]!="spells")
                    {command("say �����������ɵ��书������������㣿"); 
//return 1;}  
return ("�㲻�Ǳ�������!");
}
                  }
                     command("say �ã�ϣ�����ܵ��������޵׶������Σ�Ϊ�������⡣");
                     me->delete("betray/count", 1);
                     me->delete("betray/wudidong", 1);
                     me->delete("betrayer", 1);
                     me->set("maximum_force",me->query("max_force"));
            }        
return ("�ú�Ŭ��!");
}    
