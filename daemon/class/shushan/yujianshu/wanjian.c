#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
int i,j,k,u,damage;
string msg,str; 
weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");
        if(me->query("family/family_name")!="��ɽ��")
                return notify_fail("����ɽ�����á��򽣾�����\n");
        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");
        if( time()-(int)me->query_temp("xiao_end") < 5 )
          return notify_fail("�����ö�Ͳ����ˣ�\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("����ڹ�̫�\n");
        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("taoism", 1) < 100)
                return notify_fail("�����ʦ�����ȼ�����������ʹ����һ�У�\n");
        k=(int)me->query_skill("sword");
       j=(int)target->query_skill("dodge");
                  if(k<150)        
                return notify_fail("��Ľ������𻹲�����ʹ����һ�л������ѣ�\n");
u=1+k/50;
if (u>9) u=9;
me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIB"\n$N��������һ����"NOR,me,target);
message_vision(HIW"\n���ҿ˵�������һ����"NOR,me,target);
message_vision(HIB"\nһɲ�Ǽ�ǧ�򽣹��ƿն�������������$n"NOR,me,target);
for (i=0;i<=u;i++)
{
if (random(k+j)>j/2) {
           message_vision(HIY"\n$nһ������������һ��"NOR,me,target);
damage=100+random(150);
target->receive_damage("kee",damage);
target->receive_wound("kee",damage/2);
            COMBAT_D->report_status(target);
me->receive_damage("sen", 10);
me->add("force", -20);
}
             else {
           message_vision(HIY"\n$n�����������ò����ױܿ���һ�ֽ���"NOR,me,target);
me->receive_damage("sen", 10);
me->add("force", -20);
}
}
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"��"+me->name()+"����ɽ�ش�"NOR+HIC"���򽣾���"+HIM"ɱ���ˣ���˵ʬ�徹Ȼ���������齣��";
	                 message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
	               }
    me->set_temp("xiao_end",time());
return 1;
}
