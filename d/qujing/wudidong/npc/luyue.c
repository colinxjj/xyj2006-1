//lestat ���֮����� ����

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

/************************************************************/
void create()
{
  set_name("����", ({"lu yue","luyue", "lu", "monster"}));
    set_weight(10000000);
  set("gender", "����" );
  set("class", "yaomo" );
  set("age", 23);
  set("long", 
"����ԭΪ����������ʿ���������ι�ͨ��������£�������֮��\n"
"����Ϊ���֮�����ְ֮������������λ����\n");
  set("title", HIY"���֮�����"NOR);
  set("combat_exp", 5000000);
  set("daoxing", 5000000);
  set("attitude", "heroic");
  create_family("�ݿ�ɽ�޵׶�", 1, "����");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set_skill("unarmed", 250);
  set_skill("dodge", 250);
  set_skill("parry", 280);
  set_skill("literate", 270);
  set_skill("spells", 300); 
  set_skill("yaofa", 250);
  set_skill("sword",280);
  set_skill("qixiu-jian",290);
  set_skill("blade", 300);
  set_skill("kugu-blade", 300);
  set_skill("lingfu-steps", 250);
  set_skill("yinfeng-zhua", 250);
  set_skill("force", 250);   
  set_skill("huntian-qigong", 250);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
  set("per", 50);
  set("max_kee", 5500);
  set("max_sen", 5500);
  set("force", 5800);
  set("max_force", 5000);
  set("force_factor", 500);
  set("mana",3000);
  set("max_mana", 3000);
  set("mana_factor", 500);

  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
     (: exert_function, "zhangqi" :),
    (: perform_action, "blade.diyu" :)
   }) );
  setup();
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/npc/obj/armor")->wear();
}
/**************************************************************/

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="�ݿ�ɽ�޵׶�") {
 
 if (ob->query("obstacle/number") < 26) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�㻹���ȳ�ȥ����һ���ɣ�\n");
        command("sigh");
        return;
        }
  if (((int)ob->query("daoxing") < 1000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã����ڵ�ӿ���˵������ϣ��Ҿ��������ˡ�\n");
        command("recruit " + ob->query("id") );
        return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"�Ҳ���ʶ��ɡ�\n");
        return;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "yaomo");
    ob->set("title",HIR"Ѫ����"NOR);
}


