// shout.c
#include <ansi.h>
#include <tomud.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( !wizardp(me) )
                return notify_fail("Ŀǰ�ݲ�������� shout��\n");
        if (!arg) return notify_fail("����Ҫ���ʲô��\n");
          shout(PTEXT(HIW + me->name() +  "������Х��" + arg + "\n" NOR));
          write(PTEXT(HIW "\n��������Х��"+ arg + "\n\n" NOR));
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
 


