#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
object weapon;
        if(me->query("family/family_name")!="����ɽ���鶴")
        return notify_fail("[�������]ֻ������ɽ���Ӳſ����ã�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[�������]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_skill("wugou-jian",1) < 60)
        return notify_fail("����⹳�������������죡\n");
         if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");
         if((int)me->query("max_force") < 200 )
                return notify_fail("�������������\n");
        extra = me->query_skill("wugou-jian",1) / 15;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
      weapon=me->query_temp("weapon");
msg = HIC"�ڿ�ʽ��\n$N����"+weapon->query("name")+HIC"�ó���亮�⣡\n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
msg = HIW"׷��ʽ��\nɲ�Ǽ�$n�����ڽ���֮�У�\n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
msg = HIY"׷��ʽ��\n$N����Ʈѩһ������Ʈ�ݣ�$n��ʱ��֪��ν��У�\n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
    me->add("force",-random(2)*me->query("force_factor")-200);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
if (me->query_skill("wugou-jian",1) > 60&&me->query_skill("lingyunbu",1)>60)
{
msg = HIR"����ʽ��\n$N�����������һ�㣬����ѩ���ӿ������£��Ӷ�"+weapon->name()+HIR"��$nնȥ! \n"NOR;
message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target,me->query_temp("weapon"));
me->add("force",-random(2)*me->query("force_factor")-100);
        target->add("kee",-250);
}
       me->start_busy(2);
        return 1;
}
