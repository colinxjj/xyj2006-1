//perform baiyun ������
//created by vikee
//2000.10

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
                return notify_fail("��Ҫ��˭ʩչ��һ�С������޾�����\n");

        if(!me->is_fighting())
                return notify_fail("�������޾���ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("�������޾���������ϻ�ħ�ķ�����ʹ�á�\n");
                
if((int)me->query_skill("huomoforce",1) <100)
                return notify_fail("��Ļ�ħ�ķ����𻹲�����ʹ�����������޾�����\n");
	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("dali-bang", 1) < 100)
                return notify_fail("��Ĵ����������𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIY"\n$N���һ�������������������͵ļ����˴�������ɱ�־�ѧ�������޾���!\n"NOR,me,target);

        me->set_temp("DLB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("DLB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("DLB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("DLB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
me->delete_temp("DLB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(4);
        return 1;
}


