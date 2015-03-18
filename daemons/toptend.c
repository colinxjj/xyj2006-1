//Cracked by Roath
#include <ansi.h>
#include <mudlib.h>
#define TOPTEN_RICH 	"/topten/topten/rich.txt"
#define TOPTEN_QUESTS 	"/topten/topten/quests.txt"
#define TOPTEN_PKER	"/topten/topten/pker.txt"
#define TOPTEN_NKER 	"/topten/topten/nker.txt"
#define TOPTEN_EXP	"/topten/topten/exp.txt"
#define TOPTEN_DX	"/topten/topten/dx.txt"
#define TOPTEN_FORCE	"/topten/topten/force.txt"
#define TOPTEN_PER	"/topten/topten/per.txt"
#define TOPTEN_AGE	"/topten/topten/age.txt"
#define TOPTEN_TASK	"/topten/topten/task.txt"
#define TOPTEN_MANA	"/topten/topten/mana.txt"
#define RICH_B 		CYN"��������ʮ��"HIC"����(RICH��"NOR
#define QUESTS_B        CYN"��������ʮ��"HIC"���Ը��֣�QUESTS��"NOR
#define PKER_B 		CYN"��������ʮ��"HIC"P K ��ħ��PKER��"NOR
#define NKER_B 		CYN"��������ʮ��"HIC"N K ���֣�NKER��"NOR
#define EXP_B  		CYN"��������ʮ��"HIC"��ѧ���֣�EXP��"NOR
#define DX_B 	        CYN"��������ʮ��"HIC"���и��֣�DX��"NOR
#define FORCE_B		CYN"��������ʮ��"HIC"�������֣�FORCE��"NOR
#define PER_B		CYN"��������ʮ��"HIC"��Ů��PER��"NOR
#define AGE_B		CYN"��������ʮ��"HIC"��ǰ����AGE��"NOR
#define TASK_B		CYN"��������ʮ��"HIC"TASK���֣�TASK��"NOR
#define MANA_B		CYN"��������ʮ��"HIC"�������֣�MANA��"NOR
void topten_checkplayer(object);
int get_all_data(object,string);
int topten_del(string,string);
int topten_add(object,string);
int topten_save(string,string,string);
string topten_query(string);
string query_type();


void topten_checkplayer(object player)
{//������ò�����������컹�Ǻ����أ�������Щ����Ҫ�е����ֵģ�������Ů�Ա�
	topten_add(player,"rich");
	topten_add(player,"quests");	
	topten_add(player,"pker");
	topten_add(player,"nker");	
	topten_add(player,"exp");
	topten_add(player,"dx");
	topten_add(player,"force");
	topten_add(player,"per");	
	topten_add(player,"age");
	topten_add(player,"task");
        topten_add(player,"mana");
	return;
}

string query_type()
{
	return HIM"����"NOR+HIG"ս��"NOR+HIY"."NOR+CHINESE_MUD_NAME+"�������������͵����а�\n"+
		HIR"һ��\t"NOR+RICH_B+"\n"+
		HIR"����\t"NOR+QUESTS_B+"\n"+		
		HIR"����\t"NOR+PKER_B+"\n"+
		HIR"�ģ�\t"NOR+NKER_B+"\n"+
		HIR"�壺\t"NOR+EXP_B+"\n"+
		HIR"����\t"NOR+DX_B+"\n"+
		HIR"�ߣ�\t"NOR+FORCE_B+"\n"+
		HIR"�ˣ�\t"NOR+PER_B+"\n"+
		HIR"�ţ�\t"NOR+AGE_B+"\n"+
		HIR"ʮ��\t"NOR+TASK_B+"\n"+
              HIR"ʮһ��\t"NOR+MANA_B+"\n"+
		
		NOR;
}
int topten_save(string f_name,string b_name,string str)
{
	string *astr;
	int i;
	astr=explode(str,"\n");
	str="";
	for(i=0;i<sizeof(astr)&&i<10;i++)
		str+=astr[i]+"\n";
	if(!write_file(f_name,str,1))
		return notify_fail("�޷�д�ļ�"+f_name+"��Ȩ�޲���!���ܸ���"+b_name+"!\n");
	return 1;
}

string topten_query(string type)
{
	string b_name,f_name,str,*astr,*bstr,name,id;
	int i,j,data;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "nker":
			b_name=NKER_B;
			f_name=TOPTEN_NKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per":
			b_name=PER_B;
			f_name=TOPTEN_PER;
			break;
		case "task":
			b_name=TASK_B;
			f_name=TOPTEN_TASK;
			break;
                 case "mana":
                        b_name=MANA_B;
                        f_name=TOPTEN_MANA;
                        break;
		default:
			return query_type();
	}
	if(file_size(f_name)==-1)
		return b_name+"�������ļ���û�д�����\n";
	astr=explode(read_file(f_name),"\n");
	str=HIM"����"NOR+HIG"ս��"NOR+HIY"."NOR+CHINESE_MUD_NAME+HIY"��\n"NOR+HIC+b_name+"\n";
	for(i=0;i<sizeof(astr);i++)
	{
		bstr=explode(astr[i],";");
		str+=NOR CYN"���е�"HIR+chinese_number(i+1)+NOR"��";
		for(j=0;j<sizeof(bstr);j++)
		{
			if(sscanf(bstr[j],"%s(%s)%d",name,id,data)!=3)
				return "���ݴ���!�ļ���"+f_name+"��"+i+"�е�"+j+"�\n"+
					"�������ݣ�"+bstr[j]+"\n";
			str+=name+"("+id+")\t";
		}
		str+="\n"NOR;
	}
	return str;
}
int get_all_data(object player,string type)
{
	int total;
	switch(type)
	{
		case "rich":
    total=(int)player->query("balance")+(int)player->query("money");
			break;
		case "quests":
			total=(int)player->query("quest/number");
			break;
		case "pker":
			total=(int)player->query("PKS");
			break;
		case "nker":
			total=(int)player->query("MKS");
			break;
		case "exp":
			total=(int)player->query("combat_exp");
			break;
		case "dx":
             total=(int)player->query("daoxing");
			break;
		case "force":
			total=(int)player->query("max_force");
			break;
		case "age":
			total=(int)player->query("mud_age");
			break;
		case "per":
			if (player->query("gender")!="Ů��")
				total=-1;
			else total=player->query_per();
			break;
		case "task":
			total=(int)player->query("task_job");
			break;
                case "mana":
			total=(int)player->query("max_mana");
			break;			
		default:
			total=-1;//��-1��־���ͳ���
	}
	return total;
}

int topten_del(string pid,string type)
{
	string str,*astr,*bstr,b_name,f_name;
	int i,j,k;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "nker":
			b_name=NKER_B;
			f_name=TOPTEN_NKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per":
			b_name=PER_B;
			f_name=TOPTEN_PER;
			break;
		case "task":
      	        	b_name=TASK_B;        
			f_name=TOPTEN_TASK;
			break;
                case "mana":
                        b_name=MANA_B;
                        f_name=TOPTEN_MANA;
                        break;
		default:
			return notify_fail("û��"+type+"�������а�\n");
	}
	if(file_size(f_name)==-1)
		return notify_fail(b_name+"��û�д�����\n");
	str=read_file(f_name);
	astr=explode(str,"\n");
	for(i=0;i<sizeof(astr);i++)
	{
		if(strsrch(astr[i],pid)!=-1)//���а���id��Ϊ��
		{
			if(strsrch(astr[i],";")==-1)
			//Ϊ���ʾ����ֻ��һ��id����pid
			{
				str="";
				for(j=0;j<sizeof(astr);j++)
					if(j!=i)
						str+=astr[j]+"\n";
				return topten_save(f_name,b_name,str);
			}
			else
			{
				bstr=explode(astr[i],";");
				for(j=0;j<sizeof(bstr);j++)
					if(strsrch(bstr[j],pid)!=-1)//˵�����pid,Ӧ��ȥ��
					{
						astr[i]="";
						for(k=0;k<sizeof(bstr);k++)
							if(k!=j)
							{
								if((k+1)!=sizeof(bstr)
									&&!((j+1)==sizeof(bstr)&&j==(k+1))
								)
									astr[i]+=bstr[k]+";";
								else
									astr[i]+=bstr[k];
							}
						//����ȥ����j��ѭ��Ӧ��ֹͣ,���ǲ�Ӱ����
					}
				str=implode(astr,"\n");
				return topten_save(f_name,b_name,str);
			}
		}
	}
	return 1;
}

int topten_add(object player,string type)
{
	string str,name,id,b_name,f_name;
	string *astr;
	int i,j,data;
	if(wizardp(player))//��ֹ��ʦ�μ����а�
		return 0;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "nker":
			b_name=NKER_B;
			f_name=TOPTEN_NKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per":
			b_name=PER_B;
			f_name=TOPTEN_PER;
			break;
		case "task":
			b_name=TASK_B;
			f_name=TOPTEN_TASK;
			break;
                case "mana":
                        b_name=MANA_B;
                        f_name=TOPTEN_MANA;
                        break;	
		default:
			return notify_fail("û��"+type+"�������а�\n");
	}
	if(!objectp(player)||!userp(player))
		return 0;
	if(file_size(f_name)==-1)
	{
		str=player->short()+"("+player->query("id")+")"+
			get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	//��Ҫ����
	if(get_all_data(player,type)==-1)
		return notify_fail("���ݲ�ѯ���󣬿����ǲ�ѯ���ʹ���\n");
	//Ӧ�����ų���player��id!
	topten_del(player->query("id"),type);
	str=read_file(f_name);
	astr=explode(str,"\n");
	i=0;
	while(i<sizeof(astr))
	{
		if(sscanf(astr[i],"%s(%s)%d",name,id,data)!=3)
			if(sscanf(astr,"%s(%s)%d;%*s",name,id,data)!=3)
				return notify_fail(b_name+"�ļ����ݴ����������ʦ��\n");
		str="";
		if(data<(int)get_all_data(player,type))
		{
			//�������룬��ʱû������������ʮ�У�
			for(j=0;j<sizeof(astr);j++)
			{
				if(j==i)
					str+=player->query("name")+"("+player->query("id")+")"+
						get_all_data(player,type)+"\n";
				str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		else
		if(data==(int)get_all_data(player,type))
		{
			//���ż���
			for(j=0;j<sizeof(astr);j++)
			{
			//	if(j==i)
			//		str+=astr[j]+";"+player->query("name")+
			//			"("+player->query("id")+")"+get_all_data(player,type)+"\n";
			//	else
					str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		i++;
	}
	if(sizeof(astr)<10)
	{
		str=implode(astr,"\n")+"\n"+player->query("name")+"("+player->query("id")+
			")"+get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	return 0;
}
