//����Ц
//lestat for �ݹǵ� perform
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage;
      string msg,str; 
      if (!weapon) return 0;
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
          return notify_fail("������Ц��ֻ���޵׶����˲ſ����ã�\n");
      if ( me->query_skill("moonforce",1)     
		|| me->query_skill("ningxie-force",1)
		|| me->query_skill("lengquan-force",1)
		|| me->query_skill("zixia-shengong",1)
		|| me->query_skill("zhenyuan-force",1)
		|| me->query_skill("tonsillit",1)
		|| me->query_skill("dragonforce",1)
		|| me->query_skill("huomoforce",1)
		|| me->query_skill("wuxiangforce",1)
		|| me->query_skill("lotusforce",1)
		|| me->query_skill("xuanzong-force",1)
		|| me->query_skill("butian-force",1)
		|| me->query_skill("jiuyin-xinjing",1))
          return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ����Ц����\n");
      if( time()-(int)me->query_temp("xiao_end") < 5 )
          return notify_fail("�����ö�Ͳ����ˣ�\n");
      if (!target->is_fighting(me))
          return notify_fail("����û���ڴ�ܣ�\n");
      if (target->is_busy())
          return notify_fail("�Է������æ�����ˣ��ŵ������ɣ�\n");
      if (me->query_skill("huntian-qigong",1)<100)
          return notify_fail("����ڹ�̫��������Խ���������\n");
      if (me->query_skill("kugu-blade",1)<100) 
          return notify_fail("�㻹���ȰѾ��������ڿݹǵ����ϰɡ�\n");
      if (me->query_skill("yinfeng-zhua",1)<100) 
          return notify_fail("�������צ̫�ǿ���񹦲���Ц�����ˡ�\n");
      if (me->query_skill("qixiu-jian",1)<100)
         return notify_fail("������޽�����ô�ã�������˼���ڵ��������ۣ�\n");
      if (me->query_skill_mapped("force")!="huntian-qigong")
            return notify_fail("����Ц������ϻ�����������ʹ�á�\n");
      if (me->query_skill_mapped("unarmed")!="yinfeng-zhua")
            return notify_fail("����Ц�����������צ���ܷ���������\n");
      if (me->query_skill_mapped("sword")!="qixiu-jian")
            return notify_fail("����Ц����������޽����ܷ���������\n");
      if (me->query("force")<800)
           return notify_fail("���������̣����Գ��С�\n");

    me->add("force", -100);
    seteuid(getuid());
////����
//   target->start_busy(1);//��ס���ַ�ֹ��ʧͬʱ���������е�����.
    me->set("actions", (: call_other, SKILL_D("qixiu-jian"), "query_action" :) );   
    message_vision(HIB"$NĬ�˻���������ͻȻ��ʹ�����޽���������"+weapon->name()+HIB"ֱȡ$n��\n"NOR,me,target);
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","sword");
    enhance=me->query_skill("qixiu-jian",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("kugu-blade",1);
    damage=(damage+random(damage))/5;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target, weapon);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
////����
    me->set("actions", (: call_other, SKILL_D("yinfeng-zhua"), "query_action" :) );   
    message_vision(HIC"\n$N������ʽ���ϣ�����һЦ�������յ���צ��һ������ֱ��$n��\n"NOR,me,target);
    //weapon->unequip();
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("yinfeng-zhua",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("huntian-qigong",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    //weapon->wield();
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"��"+me->name()+"���ݿ�ɽ��ѧ"NOR+HIC"������Ц��"+HIM"�����ˣ���˵"+target->name()+"�������ϻ�����΢Ц��";
	                 message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
	               }
    me->reset_action();
    me->set_temp("xiao_end",time());
//    me->start_busy(random(2)+1);
    return 1;
}

