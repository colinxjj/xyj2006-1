//created by greenwc
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void create()
{
  set_name("��������", ({"rulai fo", "rulai", "fo"}));
  set("long", "��ȴ���ɽ������ɲ������Ӱ�٤��������ү��\n");
//�˲�����������
//LONG);
set("title", "������Ӱ�٤��");
  set("gender", "����");
  set("age", 400);
  set("str", 40);
  set("per", 40);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
       set_skill("literate", 300);
        set_skill("spells", 300);
        set_skill("buddhism", 300);
        set_skill("unarmed", 300);
        set_skill("jienan-zhi", 300);
        set_skill("dodge", 300);
        set_skill("lotusmove", 300);
        set_skill("parry", 300);
        set_skill("force", 300);
        set_skill("lotusforce", 300);
        set_skill("staff", 300);
        set_skill("lunhui-zhang", 300);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
                        (: perform_action, "hammer", "pudu" :),
	}) );
           set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
        set("force", 40000);
        set("max_force", 20000);
        set("force_factor", 1000);
        set("max_mana", 30000);
        set("mana", 60000);
        set("mana_factor", 1500);
        set("combat_exp", 20000000);
	set("daoxing", 10000000);

        create_family("�Ϻ�����ɽ", 1, "����");
  setup();

        carry_object("/d/nanhai/obj/nine-ring")->wield();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

int accept_fight(object me)
{
  command("say ʩ����Ц��\n");
return 0;
}

int attempt_apprentice(object ob)
{
	string myname=RANK_D->query_respect(ob);
            if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say �ҷ�����ͨ���" + RANK_D->query_respect(ob) + "�����������������š�\n");
return 0;
}
if (((int)ob->query_skill("buddhism", 1) < 100 )) {
      command("say ʩ���Է𷨵��о����������");
return 0;
}
if (ob->query("obstacle/number") < 26) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�㻹���ȳ�ȥ����һ���ɣ�\n");
        command("sigh");
        return 0;
        }
	command("pat " + ob->query("id") );
	command("say �ã�������ҷ��ŵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");
	command("recruit " + ob->query("id") );
ob->set("title", HIY"�ȹ��նɷ���"NOR);
        return 0; 
}

void die()
{
        if( environment() ) {
        message("sound", "\n\n��������ҡͷ̾����ԩ��������ԩ����n\n", environment());
        command("sigh");
        message("sound", "\n������������ƣ��ǲ�����������ȥ�ˡ�����\n\n", environment());
}

	destruct(this_object());
}

