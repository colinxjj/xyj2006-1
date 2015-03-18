// tomcat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��ȸ������", ({"kongque mingwang", "kongque", "mingwang", "wang"}));
	set("title",  HIG"��ĸ��ȸ����������"NOR);
	set("gender", "����" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "���֮���ӣ���ѩɽΪ�������ܣ�������ɽ���书��ʧ��");
	set("class", "yaomo");
	set("combat_exp", 5200000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 1, "��ʦ");
//	set("rank_info/respect", "��ĸ");
	set_skill("unarmed", 250);
	set_skill("cuixin-zhang", 250);
        set_skill("dodge", 300);
	set_skill("xiaoyaoyou", 240);
	set_skill("parry", 280);
        set_skill("sword", 270);
        set_skill("bainiao-jian", 280);
	set_skill("blade", 280);
	set_skill("bingpo-blade", 280);
	set_skill("throwing", 300);
        set_skill("force", 290);   
	set_skill("ningxie-force", 280);
        set_skill("literate", 280);
	set_skill("spells", 250);
	set_skill("dengxian-dafa", 250);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 3500);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);


	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="����"  )
	{
		command("kick " + ob->query("id"));
		command("say ���ߣ����ߣ���һ�������о�������\n");
		return;
	}

       if (ob->query("obstacle/number") < 26) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����Ϊʦ��Ҫ��������ȡ�����ѣ�\n");
	command("sigh");
	return;
	}
	if( (string)ob->query("family/family_name")=="��ѩɽ" ){
		if( (int)ob->query("family/generation") > 2   ){
			command("say �㲻���ҵܵܵ�ͽ�ܣ��������ա�\n");
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1000000 ){
				command("nod ");
				command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ��������п�Ϊ��\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say �㻹���ҵ��ҵܵܰɡ�\n");
			}
		}
	}

	else{
		command("hmm");
		command("say ��λ" + RANK_D->query_respect(ob) + "���ڱ��ſ�û��һ��������¡�\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
    ob->set("title", HBWHT"��ȸ�������º���ʹ"NOR);
}

void init()
{       
	object ob=this_player();

	::init();
	if ( ((string)ob->query("gender")=="����") && ((string)ob->query("class")=="bonze") && (random(3) > 1) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	
	switch( random(1) ) {
		case 0:
			command("kick " + ob->query("id"));
			command("say ����ͺ��");
			break;
	}
}


