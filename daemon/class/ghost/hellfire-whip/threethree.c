//Cracked by Roath
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int damage,enhance;
	        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����ˡ�����\n");
		        if(me->query("family/family_name") != "���޵ظ�")
                return notify_fail(HIG"�����ˡ���"+NOR"��ڤ�粻��֮�ܣ�\n");

        if(!me->is_fighting())
                return notify_fail("�����ˡ���ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if (me->query_temp("ldlh"))
           return notify_fail("������ʩ�ò������ֻ�����û�������������ˡ�����\n");
        
        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

       if((int)me->query_skill("kusang-bang", 1) < 150)
                return notify_fail("��Ŀ�ɥ�����𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("hellfire-whip", 1) < 150)
                return notify_fail("����һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");
         if((int)me->query_skill("jinghun-zhang", 1) < 150)
                return notify_fail("��ľ����Ƽ��𻹲�����ʹ����һ�л������ѣ�\n");
        if (me->query_skill_mapped("unarmed")!="jinghun-zhang")
            return notify_fail("���Ʊ�����Ͼ����Ʋ���ʹ�á�\n");
        if (me->query_skill_mapped("stick")!="kusang-bang")
            return notify_fail("���Ʊ�����Ͽ�ɥ������ʹ�á�\n");              
                       

        weapon=me->query_temp("weapon");

	message_vision(HIR"\n$N˫�ֻ�һ��Բ����Ȼ������٣������������������������ˡ����ˡ������С�\n"NOR, me);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    
    seteuid(getuid());
    me->set("actions", (: call_other, SKILL_D("jinghun-zhang"), "query_action" :) );

    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("jinghun-zhang",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("tonsillit",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target);
    me->add_temp("apply/attack",-enhance);
        
    message_vision(HIC"\n$N˫��һ��������"+weapon->name()+HIC"��ʱ��ı�ֱ����ͬһ��������\n"NOR,me);
    seteuid(getuid());
    me->set("actions", (: call_other, SKILL_D("kusang-bang"), "query_action" :) );
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","stick");
    enhance=me->query_skill("kusang-bang",1);
    me->add_temp("apply/attack", enhance);  
    COMBAT_D->do_attack(me, target,weapon);
    
    
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
    
    	
  
	me->add("force", -250);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("perform_end",time());
	return 1;
}
