#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
          int j,skill;
        string msg;

        if (me->query("fangcun/panlong_accept")!="done")
           return 0;


                 if((me->query("family/family_name") != "����ɽ���Ƕ�" ) && !wizardp(me))
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�������ʽ��?\n");

		if( !target ) target = offensive_target(me);

        if( !target

        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ʽ��ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "stick")
                return notify_fail("��������ʽ�������ù�������ʩչ��\n");

             if( (int)me->query_skill("qianjun-bang", 1) < 120 )
                return notify_fail("��ġ�ǧ������������죬����ʹ�á������˴�
����\n");

        if( (int)me->query("force") < 2000  )
                return notify_fail("�������������\n");
        if(time()-me->query_temp("pl_end")<30) return notify_fail("���ʹ��������ͻ������������\n");
   if (target->query_temp("jldl"))
         {
                    target->delete_temp("jldl");
                target->set_temp("jldl_end", time() );
 message_vision(HIR"$N����������ʽ�����ǿ���������$n�Ľ�������Ҳʧȥ�����ã�\n\n\n"NOR,me,target);
           }
         skill=me->query_skill("qianjun-bang",1);
              target->start_busy(2);
            target->add_temp("apply/dodge",-skill*2);
            target->add_temp("apply/parry",-skill*2);
		msg = HIG "$N�������У����е�$n"+HIG"����"+HIY"�������׺�"+HIG"��ʱ����������Ӱ�ӡ�\n"NOR;
        message_vision(msg, me, weapon);
      me->add_temp("apply/attack",skill);
    me->add_temp("apply/damage",skill);
       for(j=1;j<=8;j++)
   {
   msg = HIR "�����Ӱ�У�$N�ҳ���"+HIY+chinese_number(j)+HIR+"����\n"NOR;
   message_vision(msg, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
   }    
      if(me->query("id")!="take")
	{
		me->set_temp("pl_end",time());
        me->start_busy(7+random(3));
        me->add("force", -1500);
	}
    me->add_temp("apply/attack",-skill);
    me->add_temp("apply/damage",-skill);
            target->add_temp("apply/parry",skill*2);
            target->add_temp("apply/dodge",skill*2);
        return 1;
}
