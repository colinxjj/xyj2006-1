
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
int myexp, yourexp, myskill, yourskill;
int ap, dp, damage, def;
       string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ψ�Ҷ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
 return notify_fail("��Ψ�Ҷ���ֻ���޵׶����˲ſ����ã�\n");
//    if( (int)me->query_skill("yinfeng-zhua",1) < 80)
    if( (int)me->query_skill("yinfeng-zhua",1) < 980)
//    return notify_fail("�������צ����������!\n");
    return notify_fail("Ψ�Ҷ�����ʱ�ر�,�ȴ�����!\n");
    if( (int)me->query("force") < 300)
    return notify_fail("�������������!\n");
    if( (int)me->query("max_force") < 1000)
    return notify_fail("�������̫��,�޷�ʹ����Ψ�Ҷ���.\n");


        if( time()-(int)me->query_temp("duzun_end") < 3 )
return notify_fail("��������Ϣ��˳��\n");
      msg = RED
"\n$N˫Ŀ����,ʹ�����һ�С�Ψ�Ҷ���,˫צ������$n����Ǵ���.\n" NOR;
myexp= me->query("combat_exp") /1000;
yourexp=target->query("combat_exp")/1000;
myskill=me->query_skill("yinfeng-zhua",1);
yourskill=target->query_skill("dodge");
ap=myexp*myskill;
dp=yourexp*yourskill;
if (random(ap+dp)>dp/2)
{
        msg += HIR

"\nֻ����������һ��,���ǹ��۵�����,$n��ͷ���������ָ��!!\n" NOR;
damage=(int) me->query("max_kee")/2;
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee",damage,me);
                target->receive_wound("kee",damage/2,me);
                target->receive_wound("sen",damage/4,me);

       } else {
        msg += HIY "����$p���Ƕ����$P�����һ������\n" NOR;
        me->start_busy(2);


}
        if( wizardp(me) && (string)me->query("env/combat")=="verbose" )                       tell_object(me, sprintf( GRN "AP��%d��DP��%d���˺�����%d\n" NOR,
                                ap/100, dp/100, damage));

message_vision(msg, me, target);
  me->set_temp("duzun_end",time());
        return 1;
}

