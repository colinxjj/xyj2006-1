// spysword. ���̿ͽ�����
// /daemon/skill/spysword.c
// writted by mind 2001/2

#include <ansi.h>
inherit SKILL;

mapping *action = ({
      ([        "action":
"$Nһ����̾��$w���һ��"+HIG"�����Ĵ���ϧ���㡹"NOR+"����$n��$l���̶�ȥ",

                 "dodge": -35,
                 "parry": -5,
                 "damage": 60,
                 "damage_type": "����"
       ]),
        ([      "action":
"$N����üͷ���������к����Թ��$wһ��������һ��"+MAG"���콫��������"NOR+"����$n��$l",
 
                 "dodge": 50,
                "parry" : 100,
                 "damage": 55,
                "damage_type": "����"
         ]),
         ([      "action":
"$N���첻������ӹ�һ˿�ǳ$w�ݻ���һ��"+HIC"������˼��"NOR+
"ңң����$n��$l",

                "dodge": 0,
                "parry": -5,
                "damage": 70,
                "damage_type": "����"
          ]),
          ([      "action":
"$N����������������˼,��Ȼ���У�\n"
"��Ȼ�����ϯ��������������$n��$l,��һ��"+RED"��ŭ���񻨡�"NOR,

                "dodge": 30,
                "parry": -30,
                "damage": 50,
                 "damage_type": "����"
           ]),
           ([      "action":
"$N���Ƿ��裬�����滺���裬�������\n"
"һ��"+MAG"�������죬ˮãã��"NOR+"��$w����$n��$l",
 
                  "damage": 80,
                 "dodge": -40,
                "parry": 0,
                 "damage_type": "����"
           ]),
           ([      "action":
"$N΢��˫Ŀ��һ����į�����鲼�����ϣ���������,������ʱѹ������\n"
"һ��"+BLU"����į��������ʪ��"NOR+"�ɴ�$n��$l",
                  "dodge": 50,
                "parry": -50,
                  "damage": 60,
                  "damage_type": "����"
           ]),
           ([      "action":
"$Nб�г�������Х����ȴ�����˿�ɬ����ζ��$w�����·��̶���\n"
"һ��"+HIM"����˼������ƾ�"NOR+"����$n��$l",
                   "dodge": 0,
                "parry": -15,
                   "damage": 65,
                   "damage_type": "����"
             ]),
             ([      "action":
"$N����ҡͷ��˫Ŀ�������������$w��ӳ�Ų԰׵Ĺ�â"
"�������ֵ����ֶ���,һ��"+YEL"��Ī�򻨼�����С�"NOR+"����$n��$l",
                  "dodge": 40,
                "parry": -5,
                  "damage": 80,
                  "damage_type": "����"
              ]),
              (["action":               HIW"$N���е�$w��һ��ָ������$n��$l��������",NOR
                "dodge":                30,
                "parry" :               -80,
                "damage" :              50,
                "damage_type":  "����"
                ]),
                (["action":             HIW"$N����һת�����е�$w����������$n��$l���˹�ȥ",NOR
                "dodge":                50,
                "parry" :               0,
                "damage":               70,
                "damage_type":  "����"
                ]),
                (["action":             HIW"$N����һ����$wЮ�������������$n��$l",NOR
                "dodge":                40,
                "parry" :               -30,
                "damage" :              50,
                "damage_type":  "����"
                ]),
                (["action":             HIW"$N����һ�������е�$w�������ϴ���$n��$l",NOR
                "dodge":                -40,
                "parry" :               -80,
                "damage":               80,
                "damage_type":  "����"
                ]),
                (["action":             HIW"$N����$w���Ⱪ������ǧ����Ы��$n$lҧȥ",NOR
                "dodge":                60,
                "parry" :               -40,
                "damage":               100,
                "damage_type":  "����"
                ]),
                (["action":             HIW"$N���е�$w���޷����ݵ��ٶ�ֱ��$n��$l",NOR
                "dodge":                20,
                "parry" :               -30,
                "damage":               50,
                "damage_type":  "����"
                ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
        return notify_fail("�������������û�а취���̿ͽ�����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     int i;
        i=me->query("dunnoname");
        if( !me->query("dunnoname") ) {
     mapping* m_actions;
     m_actions=me->query("skill_spysword");
     if(me->query("skill_spysword")==0 )
     return action[random(7)];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
        
        return action[random(7)];
        }else {
        return action[i];
        }
     
     
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("�����������������û�а취��ϰ�̿ͽ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
          write("�㰴����ѧ����һ��̿ͽ�����\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/spysword/" + func;
}


