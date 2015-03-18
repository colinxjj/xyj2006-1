// roar.c ����ʨ�Ӻ�
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
    object *ob;
    int i, skill, damage;

    if( (int)me->query("force") < 600 )
        return notify_fail("�������������\n");

    if( environment(me)->query("no_fight") )
        return notify_fail("�����ﲻ�ܹ������ˡ�\n");

    skill = me->query_skill("force");

    me->add("force", -300);
    me->receive_damage("kee", 20);
    me->start_busy(2+random(4));
    message_vision(
    HIR "$N�������һ�����������ŷ�������һ�����춯�صľ޺�: �������־��� ��\n" NOR, me);

    ob = all_inventory(environment(me));
    for(i=0; i<sizeof(ob); i++) {
   if( !living(ob[i]) || ob[i]==me ) continue;
   if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;

   damage = skill - ((int)ob[i]->query("max_force") / 20);
   if( damage > 0 ) {
      ob[i]->receive_damage("kee", damage * 2 );
      if( (int)ob[i]->query("force") < skill * 2 )
       {  ob[i]->receive_wound("sen", damage);
          tell_object(ob[i], "�������ǰһ�������ð���ε����ң��������ŵ�̱���ڵ���!\n");
          ob[i]->start_busy(3+random(4));
       }   
   }

   if( userp(ob[i]) ) ob[i]->fight_ob(me);
   else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
    }

    return 1;
}

