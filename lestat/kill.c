// Modified by Lestat for 
// 2001.3.15
// kill.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);
int main(object me, string arg)
{
	object obj, guard_ob;
	string *killer, callname, msg;
        int obj_level, me_level;
	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(userp(obj) && obj->query("age")<16)
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");

	if(me->query("combat_exp")<500000 && userp(obj))
		return notify_fail("СС��;���ɱ�ˣ�\n");

	if(me->query("daoxing")<500000 && userp(obj))
		return notify_fail("СС��;���ɱ�ˣ�\n");	

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

    if(wizardp(obj)&&!wizardp(me)) 
       return notify_fail("ɱ��ʦ�����ǿ�������ɣ�\n");
	   
      if(!valid_kill(me,obj,0)) return 0;
        callname = RANK_D->query_rude(obj);

        if(me->query("race")=="����"){
                if(me->query("mute"))
                        msg = "\n$NͻȻ����$n��˫��ͨ�죬������Ҫ��$p�����أ���\n\n";
                else if(me->query("combat_exp") > obj->query("combat_exp")*2){
		        if(me->query("bellicosity") < 500)
                       msg = "\n$N����$n����һ�ڣ���"+callname+"��������������ʱ��"+RANK_D->query_self_rude(me)+"���쿴�㼫��˳�ۣ������ɣ���\n\n";
                    else msg = "\n$N����$n�������"+callname+"������Ǻ�"+RANK_D->query_self_rude(me)+"�����֣�������˾ȥ����һ״�ɣ���\n\n";
		        }
	        else if(obj->query("combat_exp") > me->query("combat_exp")*2){
		        if(me->query("bellicosity") < 500)
                       msg = "\n$N����$nһ����Ц����"+callname+"��������ƽʱҫ������������"+RANK_D->query_self_rude(me)+"��Ҫȡ����������\n\n";
		        else msg = "\n$N�ٺ�һЦ��$n"+callname+"�����似�����㣬���������ƴ����ҲҪ������ʬ��ϣ���\n\n";
		        }
	        else {
		        if(me->query("bellicosity") < 500)
                     msg = "\n$N����$n�ͺ�һ������"+callname+"��������Ľ��������ļ��գ���"+RANK_D->query_self_rude(me)+"������·�ɣ���\n\n";
		        else msg = "\n$N����$n�ȵ�����" + callname + "�����������ѵ����������"+RANK_D->query_self_rude(me)+"����������ɣ�\n\n";
	                }
	        }
	else msg = "\n$N���һ������Ȼ����$n��������Ҫ��$pɱ������\n\n";
           message_vision(msg, me, obj);

        if( obj->query_temp("protected")
          && objectp(guard_ob=present(obj->query_temp("protect_ob"), environment(obj)))
          && (string)guard_ob->query_temp("protect")==obj->query("id")
	  && guard_ob!=me ) {

	message_vision(HIC"$N����$n����˵�������ڴˣ����õ��ģ�\n"NOR,guard_ob,obj);
                        message_vision(HIC"$N����ǰȥ��ס��$n�Ĺ�����\n"NOR, guard_ob, me);
                        guard_ob->kill_ob(me);
			me->kill_ob(guard_ob);
		}


	do_kill(me, obj);

	return 1;
}
void do_kill(object me, object obj)
{

	me->kill_ob(obj);
	if( !userp(obj) ){
	
		if(!obj->accept_kill(me) )
		obj->kill_ob(me);

	} else {
		obj->kill_ob(me);
		tell_object(obj, HIR "�����Ҫ��" + me->name() 
			+ "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);

	}

}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ����˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ����� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬����һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 

