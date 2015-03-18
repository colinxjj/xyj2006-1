inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIW"Ԫʼ����"NOR, ({"yuanshi tianzun","tianzun", "master"}));
       set("long", "�������鶴��ʦү����ͷ�׷������ˣ����۾�������\n");
       set("title", HIW"����"NOR);
       set("gender", "����");
       set("age", 100);
        set("class", "shen");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 40);
       set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 150);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
        set("daoxing", 10000000);

       set_skill("spells",300);
        set_skill("force", 260);
        set_skill("dodge", 280);
        set_skill("parry", 300);
        set_skill("sword", 260);
        set_skill("xuanzong-force", 300);
        set_skill("lingyunbu", 270);
        set_skill("dashen-bian", 290);
        set_skill("kaitian-zhang", 250);
        set_skill("huntian-jian", 270);
        set_skill("literate", 300);
        set_skill("unarmed", 270);
        set_skill("yuxu-spells", 300);
        set_skill("wugou-jian", 280);
        set_skill("mace",270);
        map_skill("spells", "yuxu-spells");
        map_skill("dodge", "lingyunbu");
        map_skill("mace", "dashen-bian");
        map_skill("force", "xuanzong-force");
        map_skill("parry", "wugou-jian");
        map_skill("sword", "wugou-jian");
        map_skill("unarmed", "kaitian-zhang");
        
create_family("����ɽ���鶴", 1, "��");
setup();

        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/kunlun/obj/zhuxian")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="����ɽ���鶴") {
        if ((int)ob->query("daoxing") < 500000 ) {
        command("say ������ɣ����ֵĵ����ǲ��ǲ��˵㣿��" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�����޳����Ϸ�ԭ������Ϊͽ�ˣ�\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 35) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("yuxu-spells", 1) < 150 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "���������ɷ���ỹ���������������Ҳ���������ҵĽ��⣬�������գ�\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
       command("recruit " + ob->query("id") );
       ob->set("title", "Ԫʼ����մ�����"); 
    message("system", HIY"����ɽ���鶴�ֶ���һ������  "+this_player()->name()+HIW"
                     ����ɽ���鶴��������ǿ�ˡ�\n"NOR,users());
        return;
        }
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shen");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "ɱ��̫�أ��ֻ������ѣ�\n");
        return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\nԪʼ����΢��üͷ��������һ���ô������Ҳ�գ�����\n\n", environment());
        command("sigh");
        message("sound", "\nԪʼ��������һת������һ������������ա�����\n\n", environment());
        }

        destruct(this_object());
}
