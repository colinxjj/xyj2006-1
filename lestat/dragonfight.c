//�����β�����dragonfight.c
// cglaem...12/19/96.
//meipai skill(only dragon related NPCs can use it)
// tomcat �޸�
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N����Ծ��",
        "$N���˷���",
        "$$Nһ����",
        "$N����������ʹ��һ��",
        "$Nһ������ڰ��",
        "$N����һ��",
});

string* skill_tail =({
        "��˫������ɽ����֮�ƻ���$n��",
        "����׼$nһ������ץ�˹�ȥ",
        "��˫��������һ��ɨ��$n",
        "��˫��һ���ɨ��ֱ��$n����������",
        "��ֱ�Ƶ�$n�ڽں��ˡ�",
        "��ȫ��������$n",
});

mapping *action = ({
        ([      "action":
"$N����Ծ��һ��"+BLINK""+HIR"���������졹"NOR"��˫������ɽ����֮�ƻ���$n��$l",
                "dodge":                -40,
                "parry":                -40,
                "force":                180,
                "damage_type":          "����",
                "weapon" :              "˫��",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
        ]),
        ([      "action":
"$N���˷�����ͻȻ������ǰ����ָ�繳��һ��"+BLINK""+HIW"��Ǳ�����á�"NOR"����׼$n��$lһ��ץ�˹�ȥ",
                "dodge":                -60,
                "parry":                -20,
                "force":                150,
                "damage_type":          "ץ��",
                "weapon":               "������ָ",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
        ]),
        ([      "action":
"ֻ��$Nһ����˫��������һ��ɨ��$n����һ��"+BLINK""+HIB"��������β��"NOR"�����Ƿ���ʤ��",
                "dodge":                -10,
                "parry":                -20,
                "force":                150,
                "damage_type":          "����",
                "weapon":               "˫��",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
        ]),
        ([      "action":
"$N����������ʹ��һ��"+BLINK""+HIY"����ս��Ұ��"NOR"��Х���к�����ϣ���$nֱײ����",
                "dodge":                10,
                "parry":                -10,
                "force":                200,
                "damage_type":          "ײ��",
                "weapon":               "ȫ��",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
        ]),
            ([  "action":
"ֻ��$Nһ������ڰ�գ�һ��"+BLINK""+HIC"�������ĺ���"NOR"����δ��������ȫ��������$n",
                "dodge":                0,
                "parry":                -20,
                "force":                150,
                "damage_type":          "����",
                "weapon":               "����",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
        ]),
            ([  "action":
"$N����һ������$n�������һȭ������"+BLINK""+HIG"������������"NOR"�������ף������ޱ�",
                "dodge":                10,
                "parry":                -30,
                "force":                180,
                "damage_type":          "����",
                "weapon":               "ȭͷ",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
                return notify_fail("��������ķ���������տ���޷������������β�����\n");


        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����β���������֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}


int practice_skill(object me)
{
        if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
                return notify_fail("��������ķ���������տ���޷������������β�����\n");

        if( (int)me->query("sen") < 50)
                return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");

        if( (int)me->query("kee") < 50 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if( (int)me->query("force") < 20 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("kee", 30);
        me->add("force", -20);

        return 1;
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_dragonfight");
if( !me->query_temp("HTH_perform")) {
if(me->query("skill_dragonfight")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];
}else{ return action[6];}
  return action[random(sizeof(action))];
}


string perform_action_file(string func)
{
        return CLASS_D("dragon") + "/dragonfight/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("dragonfight",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"������β�������������ˣ�������β���������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�����β����������һ���µ��÷���\n"NOR);
     tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_dragonfight");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+me->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1);
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="���β�������"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"��"+arg+"��"+skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_dragonfight",m_actions);
}

