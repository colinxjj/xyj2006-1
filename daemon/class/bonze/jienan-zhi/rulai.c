// rulai jienan-zhi perform��������
// lestat 2001

#include <ansi.h>
#include <combat.h>
#include "/daemon/skill/eff_msg.h";
inherit SSERVER;

int perform(object me, object target)
{
      string msg, dodge_skill;                                
      int damage, jiali, attack, defense, p;
      object armor;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target) )
           return notify_fail("���������ơ�ֻ����ս���жԶ���ʹ�á�\n");        
      if(me->query("family/family_name") != "�Ϻ�����ɽ" )
                return notify_fail("�����Ķ�͵ѧ�����书��\n");
      if( (int)me->query_skill("jienan-zhi",1) < 100 )
           return notify_fail("��Ľ���ָ������죬����ʹ�÷����񹦡��������ơ���\n");
      
      if( (int)me->query_skill("unarmed",1) < 100 )
           return notify_fail("��Ļ����ַ�������죬����ʹ�÷����񹦡��������ơ���\n");

      if( (int)me->query_skill("lotusforce",1) < 100 )
           return notify_fail("�����̨�ķ��ȼ�����������ʹ�á��������ơ���\n");  
      
      if( (int)me->query_str() < 24 )
           return notify_fail("��������������ǿ������ʹ�á��������ơ���\n");
      
      if( (int)me->query("max_force") < 1200 )
           return notify_fail("�������̫��������ʹ�á��������ơ���\n");
      
      if( (int)me->query("force") < 800 )
           return notify_fail("�������̫���ˣ��޷�ʹ�ó����������ơ���\n");   
       
      if( (int)target->query_condition("dashouyin"))
           return notify_fail("�Է��������С��������ơ������ˣ�\n");   
                
      if( objectp(me->query_temp("weapon")) )
           return notify_fail("��������ʹ�á��������ơ���\n");                                                                              
      
      jiali = me->query("force_factor")+1;
      attack = me->query("combat_exp")/1000;
      attack += me->query_skill("unarmed");
      attack += me->query("force")/5;
      defense = target->query("combat_exp")/1000;
      defense += target->query_skill("dodge");
      defense += target->query("force")/7;
//      attack = (attack+random(attack+1))/2;
      attack += random(defense+1);
      
      damage = me->query_skill("jienan-zhi", 1)/20 * jiali;
      if(damage > 800) damage = 800;
      
      message_vision(HIR"\n$NͻȻ��ɫ���죬����Ĭ��������ԣ�˫�۹ǽ�һ���죬��Ȼ�ڿն���������$n��ǰ��ȥ����һʽ"HIY"���������ơ�"BLU"��\n"NOR,me,target);
 
//      if( attack > defense ) { 
      if( random( attack ) > defense/2 || !living(target) ) { 
      	 if( objectp(armor = target->query_temp("armor/cloth"))
      	    && armor->query("armor_prop/armor") < 600
      	    && damage > 100){
                	message_vision(HIY"ֻ���⶷�����ӡ����ӡ��$N��$n"HIY"�ϣ�Խ��Խ�󣬾�������÷��飬�ѳ�һ�����ڵ��ϣ�\n"NOR, target, armor);
                        armor->unequip();
                        armor->move(environment(target));
                        armor->set("name", "�����" + armor->query("name"));    
                        armor->set("value", 0);
                        armor->set("armor_prop/armor", 0);
                        target->reset_action();
                        }
      	 tell_object(target, RED"��ֻ���û����ؿ�һ���ʹ���Ѿ���������ǰ�أ�\n"NOR);
      	 target->apply_condition("dashouyin", 1+(me->query_str()));
      	 target->receive_damage("kee", damage,  me); 
         target->receive_wound("kee", damage/2, me);
                 target->add("force",-damage);
         if ((int)target->query("force")<0)
             {
             	target->set("force",0);
		message_vision(HIR"$nһ����Ѫ���������\n"NOR);
	     }
         p = (int)target->query("kee")*100/(int)target->query("max_kee");
         msg = damage_msg(damage, "����");
         msg += "( $n"+eff_status_msg(p)+" )\n";
         message_vision(msg, me, target);
         me->add("force", -jiali);
      	}
      else {
      	 dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
         }
//      me->add("force", -200);
      me->start_busy(1+random(2));            
      return 1;
}

 

