#include <ansi.h>

inherit ITEM;

void destroy();
void init()
{
   if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"��ָ�们��,ƬƬ��ȥ��\n");
    set("no_give","ǧ���������Ķ��������������ˣ�\n");
    set("no_drop","��ô������飬���˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
//    set("no_put","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");

  }                                    
    call_out("destroy", 120);
      if(this_player()==environment())
        add_action("do_read", "read");
      call_out("announce",random(10),this_player());
}

void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            who->query("name")+"�õ���"+name()+"��\n");
}

void create()
{
        set_name(HIW "����ת�澭��" NOR, ({"jiuzhuan zhenjing", "zhenjing"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("no_give",1);
set("no_drop",1);
set("no_get",1);
                set("long", "һ�������������ľ�ת�澭�����������ơ�����\n");
                set("value", 10000);

        }
  
        set("is_monitored",1);
        setup();
}

int do_read(string arg)
{
        int i,j;

        object me = this_player();
  
        if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
        

  

        

        i = random(900);
        j = random(1000);


        message_vision(HIB "$N�Ȳ������ط����š���ת�澭���� \n�ߺ�ߴߴ�ض�����������ˮֱ����\n" NOR, me);  
//      if (!me->query("wizgift/jinchai")) 
//      {
        me->add("wizgift/jinchai",1);
        me->add("daoxing",i+3000);
        me->add("potential",j+800);
        me->add("combat_exp",j+3000);
        log_file("static/jinchai","["+ctime(time())+"] "+
        sprintf("%s(%s)����%O\n",
         this_player()->query("name"),this_player()->query("id"),
 this_object()));
        
        tell_object (me,"��·�������Щ����������õ���"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ���
��"+chinese_number(j+3000)+"����ѧ���Լ�"+chinese_number(j+800)+"��Ǳ�ܣ�
��������������
����ת�澭������һֻ�׺׳����ȥ���㲻�����겻�ѡ�\n");
//      }
        destruct(this_object());

        return 1;
        
}
void destroy()
{
  destruct(this_object());
}
