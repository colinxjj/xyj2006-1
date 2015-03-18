// zhongkui.c
// by fjz
// tomcat �޸�
// �������õ�
#include <ansi.h>

inherit NPC;
int give_quest();

void create()
{
        set_name("��ظ", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"�����"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 112);//no rongmao description.

        set("long", "���˲�֪��ץ����ɡ�\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
        set("inquiry", ([
		"ץ��"	:	(: give_quest :),
	]));        
        setup();
        carry_object("/d/lingtai/obj/xiangpao")->wear();

}


int give_quest()
{
	object who, seal;
	mapping room;
	
	who=this_player();
     
  if ((int)who->query("combat_exp") > 1500000)
      {
           string myname=RANK_D->query_respect(who);
           command("say ��λ"+myname+"���С�²���������ݣ�");
           return 1;
      }

	if((time()-who->query("catch_ghost/last_time"))<300)
	{
		command("say ���ڻ���Ƚ�̫ƽ������ȥЪ�˰ɡ�");
		return 1;
	}
	seal=new("/d/city/obj/seal");
	seal->set("master", who);
       do{ room=LOCATION_D->random_location(); } while(!strlen(room["long"]));
	seal->set("file_name", room["file"]);
	seal->set("desc", room["long"]);
	seal->move(who);
	who->set("catch_ghost/last_time", time());
	command("nod");
	message_vision("$N��$n˵�������ŷ����㣬�㿴������д�ķ���ȥץ��ɡ�\n", 
	this_object(), who);
        who->start_busy(2);
	return 1;
}

int accept_object(object who, object ob)
{
	int reward, times;
	string msg;
	
	if(!ob->query("finished")||
		who!=ob->query("master"))
		return 0;
	command("nod");
	message_vision("$N��$n˵�����ܺã�\n", this_object(), who);
	times=who->query_temp("catch_ghost");
	msg="��������";
        reward=600+who->query_kar()*10+random(who->query_kar()*10);
	switch(random(3))
	{
		case 0:
			who->add("combat_exp", reward);
			who->add("catch_ghost/cache/wuxue", reward);
			msg+=chinese_number(reward)+"����ѧ��\n";
			break;
		case 1:
			who->add("daoxing", reward);
			who->add("catch_ghost/cache/dx", reward);
			msg+=COMBAT_D->chinese_daoxing(reward)+"���С�\n";
			break;
		default:
			who->add("potential", reward/4);
			who->add("catch_ghost/cache/pot", reward/4);
			msg+=chinese_number(reward/4)+"��Ǳ�ܡ�\n";
	}
	who->add_temp("catch_ghost", 1);
	if(who->query_temp("catch_ghost")>9)
		who->set_temp("catch_ghost", 0);
        MONITOR_D->report_system_object_msg(who, "[ץ��]"+msg);
        tell_object(who, "��"+msg);
        return 1;
}

