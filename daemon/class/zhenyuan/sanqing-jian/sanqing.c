// sanqing.c һ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
 	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("��һ�������塹ֻ����ս����ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��һ�������塹��ʼʱ��������һ�ѽ���\n");

        if (me->query_temp("jianmang"))
           return notify_fail("������ʩ�ý�â��û����������һ�������塹��\n");
        
        if( (int)me->query("force") < 300 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("sanqing-jian",1) < 60 )
                return notify_fail("������彣���������ң��޷�ʹ�á�һ�������塹��\n");

        msg = YEL "$Nʹ�����彣���ľ�����һ�������塹��һ���������������е�"+ weapon->name()+  "����㹥����һ����" NOR;
        message_vision(msg, me);
        me->add_temp("apply/attack", (int)me->query_skill("sanqin-jiang",1)/2);
        msg = HIY "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n����磡" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        message_vision(msg, me,target);
        msg =  HIW "$N���ʹ���ڶ���,"+ weapon->name()+ HIB"����$n���Ҽ磡" NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        message_vision(msg, me,target);
        msg = HIC "$N��Хһ���������ڽ�����$n����ǰ������������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        message_vision(msg, me,target);
        me->add("force", - 100);
           me->add_temp("apply/attack",-(int)me->query_skill("sanqin-jiang",1)/2);
        me->start_busy(1+random(2));

        return 1;
}

