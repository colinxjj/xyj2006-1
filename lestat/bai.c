inherit NPC;
int call_moon();
 int call_wzg();
 int call_kunlun();
 int call_putuo();
  int give_bonnet();
  int call_fangcun();
int call_xueshan();
int call_huoyundong();
    int call_longgong();
int give_gqliwu(object me);
     int call_wdd();
      int call_hell();
        int call_jjf();
		int call_pansi();
int call_shushan();
int give_gift();
#include <ansi.h>
    int give_dan();
void create()
{
                  set_name("�������", ({"akaigege","shizhe", "akaigege"}));
   set ("long", @LONG

��˵�е��������԰���õ�����Ҫ�Ĺ���
���ȥ����(ask)�����ڸ�������(putuo....)��
LONG);
       set("gender", "����");
    set("title",HIW"����"NOR);
               set("age", 21);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
        "moon":(:call_moon:),
                "huoyundong":(:call_huoyundong:),
              "jjf":(:call_jjf:),
              "wzg":(:call_wzg:),
//"���ڿ���":(:give_gqliwu:),
             "xueshan":(:call_xueshan:),
              "fangcun":(:call_fangcun:),
               "putuo":(:call_putuo:),
               "kunlun":(:call_kunlun:),
                "hell":(:call_hell:),
                "longgong":(:call_longgong:),
                 "wdd":(:call_wdd:),
				 "pansi":(:call_pansi:),
           "shushan":(:call_shushan:),
     "ħ�þ���":(:give_bonnet:),
              "��������":(:give_dan:),
              "����":(:give_dan:),
]));
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int call_moon()
{
  object who=this_player();
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
}
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("literate",60);

who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("moonforce",60);
who->set_skill("moonshentong",60);
who->set_skill("moondance",60);
 who->set_skill("baihua-zhang",60);
//  who->set_skill("jueqingbian",60);
who->set_skill("sword",60);
who->set_skill("snowsword",60);
who->set_skill("whip",60);

who->set_skill("blade",60);
who->map_skill("spells", "moonshentong");
//who->set_skill("xuanhu-blade",60);
who->map_skill("force", "moonforce");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
         command("say ���ˣ�");
who->set("yudian/skills","got");
return 1;
}
/*    int call_kunlun()
{
 object who=this_player();
if (this_player()->query("yudian/skills")=="got")
{
message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
 return 1;
}
who->set_skill("force",60);
 who->set_skill("mace",60);
who->set_skill("dashen-bian",60);
who->set_skill("wugou-jian",60);
who->set_skill("dodge",60);
who->set_skill("lingyunbu",60);
who->set_skill("force",60);
who->set_skill("xuanzong-force",60);
who->set_skill("yuxu-spells",60);
who->set_skill("unarmed",60);
who->set_skill("sword",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("kaitian-zhang",60);
who->set_skill("huntian-jian",60);
who->map_skill("spells", "yuxu-spells");
who->map_skill("force", "xuanzong-force");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
command("say ���ˣ�");
who->set("yudian/skills","got");
 return 1;
 }*/
    int call_huoyundong()
{
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
 return 1;
}
  who->set_skill("force",60);
    who->set_skill("spear",60);
      who->set_skill("huoyun-qiang",60);
  who->set_skill("dali-bang",60);
  who->set_skill("dodge",60);
    who->set_skill("stick",60);
  who->set_skill("dali-bang",60);
  who->set_skill("wuyue-spear",60);
  who->set_skill("huomoforce",60);
    who->set_skill("moyun-shou",60);
  who->set_skill("parry",60);
  who->set_skill("pingtian-dafa",60);
  who->set_skill("spells",60);
  who->set_skill("stick",60);
  who->set_skill("unarmed",60);
  who->set_skill("moshenbu",60);
  who->set_skill("literate",60);
  who->map_skill("spells", "pingtian-dafa");
  who->map_skill("force", "huomoforce");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
 who->set("yudian/skills","got");
 return 1;
 }
int call_kunlun()
{
  object who=this_player();
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
}
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("xuanzong-force",60);
who->set_skill("yuxu-spells",60);
who->set_skill("lingyunbu",60);
who->set_skill("kaitian-zhang",60);
who->set_skill("mace",60);
who->set_skill("huntian-jian",60);
who->set_skill("dashen-bian",60);
who->set_skill("sword",60);
who->set_skill("wugou-jian",60);
who->map_skill("spells", "yuxu-spells");
who->map_skill("force", "xuanzong-force");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
         command("say ���ˣ�");
who->set("yudian/skills","got");
return 1;
}
  int call_fangcun()
 {
    object who=this_player();
             if (this_player()->query("yudian/skills")=="got")
   {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
  }
 who->set_skill("force",60);
 who->set_skill("spells",60);
 who->set_skill("literate",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("wuxiangforce",60);
 who->set_skill("dao",60);
 who->set_skill("jindouyun",60);
 who->set_skill("puti-zhi",60);
 who->set_skill("sword",60);
// who->set_skill("liangyi-sword",60);
 who->set_skill("qianjun-bang",60);
 who->set_skill("stick",60);
who->map_skill("force", "wuxiangforce");
 who->map_skill("spells", "dao");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
 who->set("yudian/skills","got");
return 1;
}
int give_gift()
{
object who=this_player();
         if (this_player()->query("jjf/yudian")=="got")
{
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
  return 1;
}
message_vision("С��������������������!\n$nͻȻ�о��ޱ�ǿ��\n",this_object(),this_player());
     who->set("jjf/yudian","got");
return 1;
}
    int call_putuo()
   {
     object who=this_player();
              if (this_player()->query("yudian/skills")=="got")
   {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
    }
   who->set_skill("force",60);
   who->set_skill("spells",60);
  who->set_skill("literate",60);
  who->set_skill("dodge",60);
   who->set_skill("parry",60);
  who->set_skill("unarmed",60);
  who->set_skill("jienan-zhi",60);
  who->set_skill("lotusforce",60);
  who->set_skill("buddhism",60);
  who->set_skill("lotusmove",60);
  who->set_skill("staff",60);
  who->set_skill("lunhui-zhang",60);
who->map_skill("spells", "buddhism");
who->map_skill("force", "lotusforce");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
  who->set("yudian/skills","got");
return 1;
}
     int call_longgong()
    {
       object who=this_player();
                if (this_player()->query("yudian/skills")=="got")
    {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
 return 1;
    }
   who->set_skill("force",60);
  who->set_skill("spells",60);
   who->set_skill("literate",60);
  who->set_skill("dodge",60);
   who->set_skill("parry",60);
 who->set_skill("unarmed",60);
   who->set_skill("dragonforce",60);
 who->set_skill("seashentong",60);
 who->set_skill("dragonstep",60);
 who->set_skill("dragonfight",60);
 who->set_skill("fork",60);
 who->set_skill("hammer",60);
 who->set_skill("huntian-hammer",60);
 who->set_skill("fengbo-cha",60);
who->map_skill("force", "dragonforce");
who->map_skill("spells", "seashentong");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
   who->set("yudian/skills","got");
 return 1;
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  say(name()+"���ص�˵������Ҫ���������Ұ�����������ֻ��һ�λ��ᣡ��\n");
}
  int call_wdd()
 {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
 }
 who->set_skill("force",60);
 who->set_skill("spells",60);
  who->set_skill("literate",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("huntian-qigong",60);
 who->set_skill("yaofa",60);
 who->set_skill("dao",60);
 who->set_skill("throwing",60);
 who->set_skill("lingfu-steps",60);
 who->set_skill("yinfeng-zhua",60);
 who->set_skill("kugu-blade",60);
 who->set_skill("qixiu-jian",60);
 who->set_skill("sword",60);
 who->set_skill("blade",60);
who->map_skill("spells", "yaofa");
who->map_skill("force", "huntian-qigong");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
who->set("yudian/skills","got");
 return 1;
}
  int call_xueshan()
 {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
  return 1;
 }
who->set_skill("force",60);
 who->set_skill("spells",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("literate",60);
 who->set_skill("xiaoyaoyou",60);
 who->set_skill("throwing",60);
 who->set_skill("ningxie-force",60);
 who->set_skill("dengxian-dafa",60);
 who->set_skill("cuixin-zhang",60);
 who->set_skill("bainiao-jian",60);
 who->set_skill("sword",60);
 who->set_skill("bingpo-blade",60);
 who->set_skill("blade",60);
who->map_skill("force", "ningxie-force");
who->map_skill("spells", "dengxian-dafa");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
 who->set("yudian/skills","got");
 return 1;
}
  int call_hell()
  {
    object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
}
 who->set_skill("force",60);
  who->set_skill("spells",60);
  who->set_skill("dodge",60);
  who->set_skill("literate",60);
  who->set_skill("parry",60);
  who->set_skill("unarmed",60);
  who->set_skill("ghost-steps",60);
  who->set_skill("gouhunshu",60);
  who->set_skill("tonsillit",60);
  who->set_skill("kusang-bang",60);
  who->set_skill("hellfire-whip",60);
  who->set_skill("jinghun-zhang",60);
  who->set_skill("zhuihun-sword",60);
  who->set_skill("sword",60);
  who->set_skill("stick",60);
  who->set_skill("whip",60);
who->map_skill("force", "tonsillit");
who->map_skill("spells", "gouhunshu");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
 who->set("yudian/skills","got");
return 1;
}
   int call_pansi()
    {
       object who=this_player();
                if (this_player()->query("yudian/skills")=="got")
    {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
 return 1;
    }
   who->set_skill("force",60);
  who->set_skill("spells",60);
   who->set_skill("literate",60);
  who->set_skill("dodge",60);
   who->set_skill("parry",60);
 who->set_skill("unarmed",60);
   who->set_skill("jiuyin-xinjing",60);
 who->set_skill("pansi-dafa",60);
 who->set_skill("yueying-wubu",60);
 who->set_skill("lanhua-shou",60);
  who->set_skill("chixin-jian",60);
   who->set_skill("whip",60);
 who->set_skill("sword",60);
 who->set_skill("qin",60);
 who->set_skill("qingxia-jian",60);
 who->set_skill("yinsuo-jinling",60);
who->map_skill("force", "jiuyin-xinjing");
who->map_skill("spells", "pansi-dafa");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
   who->set("yudian/skills","got");
 return 1;
}
int call_wzg()
{
  object who=this_player();
           if (this_player()->query("yudian/skills")=="got")
{
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
 return 1;
  }
 who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("dodge",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("baguazhen",60);
who->set_skill("taiyi",60);
who->set_skill("zhenyuan-force",60);
who->set_skill("wuxing-quan",60);
who->set_skill("kaishan-chui",60);
who->set_skill("hammer",60);
who->set_skill("fumo-zhang",60);
who->set_skill("staff",60);
who->set_skill("xiaofeng-sword",60);
who->set_skill("sword",60);
who->set_skill("yange-blade",60);
who->set_skill("blade",60);
who->set_skill("sanqing-jian",60);
who->map_skill("force", "zhenyuan-force");
who->map_skill("spells", "taiyi");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
 who->set("yudian/skills","got");
return 1;
}
  int call_jjf()
  {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
   {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
 }
 who->set_skill("force",60);
   who->set_skill("spells",60);
   who->set_skill("dodge",60);
   who->set_skill("parry",60);
   who->set_skill("unarmed",60);
   who->set_skill("literate",60);
//   who->set_skill("archery",50);
   who->set_skill("bawang-qiang",60);
   who->set_skill("changquan",60);
   who->set_skill("lengquan-force",60);
   who->set_skill("mace",60);
   who->set_skill("spear",60);
   who->set_skill("wusi-mace",60);
   who->set_skill("yanxing-steps",60);
   who->set_skill("baguazhou",60);
who->map_skill("force", "lengquan-force");
who->map_skill("spells", "baguazhou");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
 who->set("yudian/skills","got");
return 1;
}
    int call_shushan()
  {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
   {
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿺α�����̰���أ�");
return 1;
 }
 who->set_skill("force",60);
   who->set_skill("spells",60);
   who->set_skill("dodge",60);
   who->set_skill("parry",60);
   who->set_skill("unarmed",60);
   who->set_skill("literate",60);
//   who->set_skill("archery",50);
//   who->set_skill("bawang-qiang",50);
who->set_skill("hunyuan-zhang",60);
who->set_skill("zixia-shengong",60);
   who->set_skill("yujianshu",60);
   who->set_skill("sword",60);
//   who->set_skill("songhe-sword",60);
who->set_skill("sevensteps",60);
who->set_skill("taoism",60);
who->map_skill("force", "zixia-shengong");
who->map_skill("spells", "taoism");
message_vision("�����������@#$%&%*#$##@@!��\n",this_object(),this_player());
          command("say ���ˣ�");
 who->set("yudian/skills","got");
return 1;
}
int give_dan()
{
object dan;
object who=this_player();
if (!userp(who))
{
command("hate");
command("say С������ȥ���������");
command("qi");
return 1;
}
         if (this_player()->query("lestat/gift")=="got")
{
          message_vision("$N����$n����һ����\n",this_object(),this_player());
       command("say ����ֻ��һ�ݣ�����Ͳ��ٸ��ˣ�");
  return 1;
}

who->set("combat_exp",80000);
who->set("daoxing",90000);
who->set("force",800);
who->set("max_force",800);
who->set("max_mana",800);
who->set("mana",800);
who->set("maximum_force",800);
who->set("maximum_mana",800);
who->set("potential",80000);
message_vision("$N��һָ��$nֻ���������������ƣ��ƺ���Ϊ����������\n",this_object(),this_player());
     who->set("lestat/gift","got");
return 1;
}
int give_bonnet()

 {

 object bonnet;

 object who=this_player();

if (!userp(who))

{ 

command("grin");

command("say ʲô����,С���Ұ������Ƥ����");

return 1;

}
      bonnet=new("/lestat/faguan");

bonnet->move(who);
message_vision("$N����һ�ӣ�$N���һ��ħ�þ��ڡ�\n$N��$nһ��ħ�þ��ڡ�\n",this_object(),this_player());

           command("say �ú���Ŷ,������˻���,С�ĺ�ɽ����ץ�㣡");

command("snicker");
return 1;
  }

int give_gqliwu(object me)
{
	me=this_player();
	
 if(me->query("gift/02gq"))   {
    write(HIY"���Ѿ��õ�������ɣ�\n"NOR);
			return 1;
	}
          write(HIY"���տ���!\n��õ���50����У�30000��ѧ��30000Ǳ�ܡ�\n"NOR);
        me->add("potential",30000);
        me->add("daoxing",50000);
         me->add("combat_exp",30000);
me->set("gift/02gq",1);
        me->save();
	return 1;
}
