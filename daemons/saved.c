// saved.c
// �Զ�����ϵͳ

#include <ansi.h>

inherit F_DBASE;

private void auto_save();
private void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "���̾���");
        CHANNEL_D->do_channel( this_object(), "sys", "�Զ�����ϵͳ�Ѿ�������");
        auto_save();
}
private void auto_save()
{
        int i,player;
        object *ob,link_ob;

        seteuid(getuid());

        ob = filter_array(children(USER_OB),(: userp :));
        i=sizeof(ob);

        for( i=0;i<sizeof(ob);i++) {
                if(!environment(ob[i]) )continue;
                if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
                ob[i]->save();
                link_ob->save();
                player++;
                if( (int)link_ob->save() && (int)ob[i]->save())
                        message("system",HIG"��������Ѿ����洢��\n"NOR,ob[i]);
                else
                        message("system", HIG"������ϴ洢ʧ�ܣ��뾡����ϵ��ʦ��\n"NOR,ob[i]);
        }
        CHANNEL_D->do_channel(this_object(),"sys",sprintf("����%dλʹ�������ϱ����棡ϵͳ�����"+ reclaim_objects() +"��������",player));
        remove_call_out("auto_save");
        call_out("auto_save",300);
        return;
}
