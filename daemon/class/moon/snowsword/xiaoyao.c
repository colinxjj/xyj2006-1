#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
return notify_fail("��Ҫ��˭ʩչ��һ�С���ңһЦ����\n");
        if(!me->is_fighting())
      return notify_fail("����ңһЦ��ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 800)
                return notify_fail("�������������\n");
if((int)me->query("force") < 500 )
     return notify_fail("����������㣡\n");
if((int)me->query("sen") < 200)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
           if((int)me->query_skill("snowsword", 1) < 100)
return notify_fail("���snowsword���𻹲�����ʹ����һ�л������� !\n");
        me->delete("env/brief_message");
   target->delete("env/brief_message");
message_vision(HIW"\n"+HIY"$N��̾����"+HIW"���ŵ���Ϧ�����࣬��Ҳ���� "+HIY"ͻȻ������һЦ\n"+
NOR"\n"+HIY"                    ����$nһ����������ɱ�֣�\n"NOR,me,target);
        me->set_temp("XY_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("XY_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      me->set_temp("XY_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("QJB_perform");
//target->receive_damage("kee",((int) me->query("max_kee")/6));
//target->receive_wound("kee",((int) me->query("max_kee")/4));
        me->receive_damage("sen", 100);
	me->add("force",-100);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
me->start_busy(2);
        return 1;
}
