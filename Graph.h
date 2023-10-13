#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define Max 100 //���ص���
#define PASSWORD "18cufers" //����Ա����
#define INFINITY 1000000 //·����󳤶�
#define DELAY 982337369 //�ӳٳ���
#define CONFIRMATION "QUEREN" //ȷ����
bool isAdmin; //�û����
void show(void);//������еص�
void Stu(void);//�û�ϵͳ
void Admin(void);//����Աϵͳ
void intro(void);//�ص����
void sortRisk(void);//�ص���յȼ�����
void Dijkstra(void);//�����û����ڵص��������ص�ľ���
void Floyd(void);//�����û�ָ���������ص������·������
void alter(void);//�޸ĵص���Ϣ
void addSpot(void);//��ӵص�
void delSpot(void);//ɾ���ص�
void addPath(void);//��ӵ�·
void delPath(void);//ɾ����·
void CreateGraph(void); //������ͼ

typedef int EdgeType;   //������������
typedef struct {
    int num;
    char name[100];
    char refer[1000];
    int riskLevel;  //��1-3�ֱ�Ϊ�ͷ���С�����еȷ���С�����߷���С��
}VexType;

typedef struct {   //�ڽӾ���ͼ
    VexType vex[Max];
    EdgeType edge[Max][Max];
    int vn;//������
    int en;//����
}MGraph;

static MGraph XFD;  //�·��ص�ͼ

int flag = 1;

void show(void)//   ��ӡ��ͼ��Ϣ
{
    printf("��ǰ��ͼ���Ѿ�¼��ĵص��У�\n");
    for (int i = 0;i < XFD.vn;i++)
        printf("%d : %s\n", i + 1, XFD.vex[i].name);
}

void CreateGraph(void)
{
    XFD.vn = 19;
    XFD.en = 32;
    for (int i = 0;i < Max;i++)
    {
        XFD.vex[i].num = i + 1;
    }
    for (int i = 0;i < Max;i++)
        for (int j = 0;j < Max;j++)
            XFD.edge[i][j] = INFINITY;

    strcpy(XFD.vex[0].name, "���ؼ�԰");
    strcpy(XFD.vex[0].refer, "С��λ�ڱ����з�̨����Ȧ·��������·����·������Լ50��(���ػ�԰�Ƶ��ϲ�)����ΪA��B��C��������");
    strcpy(XFD.vex[1].name, "����԰");
    strcpy(XFD.vex[1].refer, "С��λ�ڱ����з�̨���Ƴ�·���ش����������廷���������250000ƽ���ף��ݻ���1.02���̻���25%����������50--120ƽ���ף��ܱ���ʩ��Ϊ���ơ�");
    strcpy(XFD.vex[2].name, "���׽���");
    strcpy(XFD.vex[2].refer, "С��λ�ڱ����з�̨���Ƴ�·���г����ֽ��㴦����30��·�����ش����������廷��2003�꽨�ɣ��������Ϊ430000ƽ���ף��̻��ʴ�35%��ӵ��ͣ��λ1824�����ܱ���ʩ��Ϊ�ѷ���");
    strcpy(XFD.vex[3].name, "����С��");
    strcpy(XFD.vex[3].refer, "С��λ�ڱ����з�̨�������·��ؾ��������뾩����·���㴦�����࣬�ش����������廷��2010�꽨�ɣ��������Ϊ168000ƽ���ף��̻��ʴ�31%��ӵ��ͣ��λ1397����");
    strcpy(XFD.vex[4].name, "�������Է");
    strcpy(XFD.vex[4].refer, "С��λ�ڱ����з�̨����̨��·21�ţ��ش����������廷���������·��ظ������˶����׶³���һ�㾡�����С�");
    strcpy(XFD.vex[5].name, "����԰");
    strcpy(XFD.vex[5].refer, "С��λ�ڱ����з�̨��������·���ش����������廷��2002�꽨�ɣ��������Ϊ800000ƽ���ף��̻��ʴ�38%�����ͣ��λ150/�¡�");
    strcpy(XFD.vex[6].name, "�콾��԰");
    strcpy(XFD.vex[6].refer, "С��λ�ڱ����з�̨���˼���·9��Ժ���ش����������廷��2011�꽨�ɣ��������Ϊ267000ƽ���ף��̻��ʴ�30%��ӵ��ͣ��λ1837����");
    strcpy(XFD.vex[7].name, "�泽��԰");
    strcpy(XFD.vex[7].refer, "С��λ�ڱ����з�̨���������Ϸ���·88��Ժ���ش����������廷��2000�꽨�ɣ��������Ϊ160202ƽ���ף��̻��ʴ�36%��ӵ��ͣ��λ600�����ҡ�");
    strcpy(XFD.vex[8].name, "�׿������");
    strcpy(XFD.vex[8].refer, "С��λ�ڱ����з�̨������·68��Ժ��2015�꽨�ɣ��������Ϊ418000ƽ���ף��̻��ʴ�30%����Ȩ70�ꡣ");
    strcpy(XFD.vex[9].name, "������԰");
    strcpy(XFD.vex[9].refer, "С��λ�ڱ��������Ļ���·129�ţ��ش����������廷���ܱ�������ʩ�����ƣ��ڵڰ���ѧ������У���棬��ͨ�ǳ����㣬�����9���߿���·����վA�ںܽ�������534�ס�");
    strcpy(XFD.vex[10].name, "ŷ������ҽԺ");
    strcpy(XFD.vex[10].refer, "����ŷ������ҽԺλ�ڱ����з�̨���·��س������Ͽ�8�ţ���һ����������ҽԺ��ҽԺ���������ơ��ڿơ���ơ���ҽ�ơ����Ƶȡ�");
    strcpy(XFD.vex[11].name, "�·��ظ��ױ���Ժ");
    strcpy(XFD.vex[11].refer, "��̨�����ױ���Ժʼ����1979�꣬ǰ��Ϊ��̨�����ױ�������2000���Ǩ����ұ��ֵ���������Ժ�� 2013��8��Ǩַ���Ұ������֣�2017���ڷ�̨��·�����Ժ����һԺ��ַ���칫���2.6��ƽ���ף���Ҫҵ����ң����ơ����ơ����ơ���ͯ�����ۺϷ�չ�������ġ������������ġ�Ƥ���ơ���ǻ�ơ�������Ƶȣ����������У����ܿơ�����ơ�����ơ�ҩ���Ƶȡ�");
    strcpy(XFD.vex[12].name, "����������ҽҽԺ");
    strcpy(XFD.vex[12].refer, "��������������ҽҽԺ�㼯�����������Ѻ�ҽԺ���й���ҽ��ѧԺ�㰲��ҽԺ������������ҽ���ҽԺ��70��λר��������������ơ����˿ơ���ҽ�ڿơ���Ѫ�ܿơ��ڷ��ڿơ�Ƣθ���ơ��ε��ơ������ơ����ơ����ơ�Ƥ���ơ���ʹ�����ҽ��ơ���ǻ�ơ���ҽ�ڿơ���Ŀơ����ÿƵ��ٴ����ҡ�ҽԺ���в���60���ţ����䱸�������Ҽ������Ƚ����ٴ������豸�������������ߵľ�ҽ���󡣱�������������ҽҽԺ�Ǳ�����ҽ��������������趨�㼴�ɳֿ���ҽ��ҽԺ�����������ܱ߽�ͨ��������Ϊ���ṩȫ�����ʵ�ҽ������");
    strcpy(XFD.vex[13].name, "��̫��԰ҽԺ");
    strcpy(XFD.vex[13].refer, "ҽԺλ�ڱ�����̨��԰·�Ǻӳ�1��Ժ18��¥����һ����Ӫ/�ۺ�ҽԺ��ҽԺ�ٷ�΢��ƽ̨�ᶨ�ھ����Żݻ�������ǳ��ﻹ�Ǹ��ֻҪ��΢��ƽ̨ԤԼ�Ϳ�������һ�����Żݴ������ڼ��ջ����ȡ���˺��ѣ����Ͱ�̫ʵ��������");
    strcpy(XFD.vex[14].name, "��������ҽԺ");
    strcpy(XFD.vex[14].refer, "ҽԺλ�ڱ����з�̨��֣������6�ţ���һ���ۺ�ҽԺ���Ǳ�����ҽ������ҽԺ��ҽԺ����ѪҺ�ڿơ����ơ���ơ��ۿơ����Ǻ�ơ���ǻ�ơ�����ơ�ҽѧӰ��ơ�ҽѧ����Ƶ��ٴ���ҽ�����ҡ�");
    strcpy(XFD.vex[15].name, "��������ҽԺ");
    strcpy(XFD.vex[15].refer, "�й���������ҽѧ����Ժ�����ڶ�ҽԺ����������ҽԺ������ҽԺЭ��ҽԺ���й�����ҽѧ��ѧԺЭ��ҽԺ��������ҽҩ����ҽר��ר���ٴ����أ������п�Ѫ��ѪҺ��ҽѧ�о�Ժ�ٴ�ҽԺ��������ҽ������ҽԺ�����������˿�ǩԼ����ҽԺ���������ҹ����׶�������̨�������Դ�ͳ����ҽ��ҩΪ�ص㿪�����о����ٴ�ҽԺ��ҽԺ����ռ��8Ķ����������Ѿ�������8000��ƽ�ס� ҽԺ��ģ: ����������ҽԺ��Ϊ�ۺ�¥��סԺ¥����ҽ�á��񿵿���¥�Ĵ�¥�����в�����260�ţ������ڿơ���ơ������ơ����ơ���ǻ�ơ���ҽѪҺ���ơ���ҽ����Ѫ�ܿơ��񾭿������ġ���ҽ�ε����ơ���ҽƤ���ơ���ҽ���˿ơ���ҽ����ơ���ҽ��������ҽ���ʿơ���ҽ�����ơ���ҽ����ר�ơ���ҽ���Ƶȡ�");
    strcpy(XFD.vex[16].name, "������̳ҽԺ");
    strcpy(XFD.vex[16].refer, " ҽԺλ�ڱ����з�̨�����Ļ���·119�ţ�ʼ����1956��8��23�գ�ռ�����181581ƽ���ף��ܽ������ 352294ƽ���ף���һ���������Ϊ�ȵ������񾭿�ѧ��ȺΪ��ɫ����ҽ�ơ���ѧ�����С�Ԥ��Ϊһ��������׵��ۺ���ҽԺ���Ǳ�����ҽ������ҽԺ��");
    strcpy(XFD.vex[17].name, "����������ҽԺ");
    strcpy(XFD.vex[17].refer, "������̨��������ҽԺҽԺ��2009��5�³�������һ��ҽ������ҽԺ����Ҫ��Ӫ��Χ:�ڿơ���ơ�������;����רҵ����ǻ�ơ�ҽѧ�����;�ٴ���Һ��ѪҺרҵ; �ٴ���ѧ����רҵ��ҽѧӰ���; X�����רҵ;�������רҵ;�ĵ����רҵ����ҽ��;�ڿ�רҵ;������רҵ;Ƥ����רҵ;���˿�רҵ;��Ŀ�רҵ;���ÿ�רҵ;����ҽѧרҵ��");
    strcpy(XFD.vex[18].name, "����ʱ������ҽҽԺ");
    strcpy(XFD.vex[18].refer, "ҽԺλ�ڱ����з�̨�������Ļ��Ĺ�԰���棬�������ķ�̨�Ƽ�԰�����ڡ�ҽԺ����������Ժ���̲�������ľ���죬��ˮ�������Ǳ�����԰��ʽ��ҽԺ.ҽԺӵ���������סԺ�������¥�Ȳ��ţ�ҽ�Ƽ��������ۺ�ӵ�и����Ƚ���ҽѧ�����豸��");

    XFD.edge[0][1] = XFD.edge[1][0] = 150;
    XFD.edge[0][4] = XFD.edge[4][0] = 580;
    XFD.edge[0][7] = XFD.edge[7][0] = 1630;
    XFD.edge[0][11] = XFD.edge[11][0] = 899;
    XFD.edge[1][2] = XFD.edge[2][1] = 200;
    XFD.edge[1][8] = XFD.edge[8][1] = 1750;
    XFD.edge[1][11] = XFD.edge[11][1] = 2100;
    XFD.edge[2][11] = XFD.edge[11][2] = 1400;
    XFD.edge[2][3] = XFD.edge[3][2] = 910;
    XFD.edge[3][8] = XFD.edge[8][3] = 2200;
    XFD.edge[3][6] = XFD.edge[6][3] = 2400;
    XFD.edge[3][10] = XFD.edge[10][3] = 1300;
    XFD.edge[4][5] = XFD.edge[5][4] = 220;
    XFD.edge[4][9] = XFD.edge[9][4] = 2940;
    XFD.edge[4][16] = XFD.edge[16][4] = 4300;
    XFD.edge[4][14] = XFD.edge[14][4] = 4000;
    XFD.edge[4][15] = XFD.edge[15][4] = 4180;
    XFD.edge[5][6] = XFD.edge[6][5] = 1510;
    XFD.edge[5][14] = XFD.edge[14][5] = 3800;
    XFD.edge[5][12] = XFD.edge[12][5] = 4000;
    XFD.edge[5][13] = XFD.edge[13][5] = 4200;
    XFD.edge[6][15] = XFD.edge[15][6] = 5300;
    XFD.edge[6][13] = XFD.edge[13][6] = 4200;
    XFD.edge[6][10] = XFD.edge[10][6] = 3700;
    XFD.edge[7][8] = XFD.edge[8][7] = 320;
    XFD.edge[7][9] = XFD.edge[9][7] = 1620;
    XFD.edge[7][18] = XFD.edge[18][7] = 3900;
    XFD.edge[7][16] = XFD.edge[16][7] = 1500;
    XFD.edge[8][16] = XFD.edge[16][8] = 2000;
    XFD.edge[8][18] = XFD.edge[18][8] = 3900;
    XFD.edge[9][17] = XFD.edge[17][9] = 816;
    XFD.edge[9][16] = XFD.edge[16][9] = 2400;
    
    XFD.vex[0].riskLevel=3;
    XFD.vex[1].riskLevel=3;
    XFD.vex[2].riskLevel=2;
    XFD.vex[3].riskLevel=3;
    XFD.vex[4].riskLevel=2;
    XFD.vex[5].riskLevel=2;
    XFD.vex[6].riskLevel=2;
    XFD.vex[7].riskLevel=1;
    XFD.vex[8].riskLevel=1;
    XFD.vex[9].riskLevel=1;
}

void alter(void)  //�޸ĵص���Ϣ
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("��ͼ�����κεص㣬������ӵص㣡\n");
        return;
    }
    show();
    int a;
    printf("��������Ҫ�޸���Ϣ�ĵص��ţ�\n");
    scanf("%d", &a);
    while (a<1 || a>XFD.vn)
    {
        printf("����������Ӧλ��1��%d֮�䣬���������룡\n", XFD.vn);
        scanf("%d", &a);
    }
    int i;
    printf("����������Ҫ�޸ĵĶ���1.�ص����ƻ��飻2.�ص���յȼ�����\n");
    scanf("%d", &i);
    if(i==1){
        char newName[100];
        char newRefer[1000];
        printf("�ص㵱ǰ����Ϊ%s,��������ĺ�����ƣ�\n", XFD.vex[a - 1].name);
        scanf("%s", newName);getchar();
        printf("�ص㵱ǰ�ļ���ǣ�\n%s\n����������ĺ�ļ�飺\n", XFD.vex[a - 1].refer);
        scanf("%s", newRefer);getchar();
        printf("�����޸ĵص���Ϣ...\n");
        strcpy(XFD.vex[a - 1].name, newName);
        strcpy(XFD.vex[a - 1].refer, newRefer);
        
    }
    
    else if(i==2){
        int newlevel;
        printf("�ص㵱ǰ�ȼ�Ϊ%d����������ĺ�ķ��յȼ���1-�ͷ���С����2-�еȷ���С����3-�߷���С������\n", XFD.vex[a - 1].riskLevel);
        scanf("%d", &newlevel);
        printf("�����޸ĵص���Ϣ...\n");
        XFD.vex[a - 1].riskLevel=newlevel;
    }
        
    for (long long i = 0;i < DELAY;i++);
    printf("��Ϣ�޸ĳɹ���\n");
    printf("�Ƿ�������������ص���Ϣ����=1����������=�˳�\n");

    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        alter();
}





void addSpot(void)  //��ӵص�
{
    //system("clear");
    if (XFD.vn >= Max)
    {
        printf("��ͼ�������޷�������µĵص㣡\n");
        return;
    }
    if (XFD.vn > 0)
        show();
    char newName[100];char newRefer[500];
    printf("��������Ҫ���ӵĵص����ƣ�\n");
    scanf("%s", newName);getchar();
    printf("������%s�ļ�飨���ɶ���200�֣���\n", newName);
    scanf("%s", newRefer);getchar();

    int m = 0;
    if (XFD.vn >= 1) {
        show();
        printf("�����������ص�����ڵص������\n");
        scanf("%d", &m);
        while (m<0 || m>XFD.vn) {
            printf("����������ڵص����Ӧλ��0��%d֮�䣬���������룡\n", XFD.vn);
            scanf("%d", &m);
        }
        for (int i = 0;i < m;i++)
        {
            int a, d;
            printf("������%s�ĵ�%d�����ڵص���:\n", newName, i + 1);
            scanf("%d", &a);
            while (a<1 || a>XFD.vn || XFD.edge[a - 1][XFD.vn] != INFINITY)
            {
                if (a<1 || a>XFD.vn)
                    printf("����������Ӧλ��1��%d֮�䣬���������룡\n", XFD.vn);
                if (XFD.edge[a - 1][XFD.vn] != INFINITY)
                    printf("�벻Ҫ�ظ��������ڵص㣬�������룡\n");
                scanf("%d", &a);
            }
            printf("������%s��%s֮��ľ���:\n", newName, XFD.vex[a - 1].name);
            scanf("%d", &d);
            while (d <= 0 || d >= INFINITY)
            {
                printf("��������������������룡\n");
                scanf("%d", &d);
            }
            XFD.edge[a - 1][XFD.vn] = XFD.edge[XFD.vn][a - 1] = d;//���·������
        }
    }
    printf("������ӵص�...\n");
    strcpy(XFD.vex[XFD.vn++].name, newName);
    strcpy(XFD.vex[XFD.vn - 1].refer, newRefer);
    XFD.en += m;
    for (long long i = 0;i < DELAY;i++);
    printf("�µص���ӳɹ���\n");
    printf("�Ƿ�������������ص㣿��=1����������=�˳�\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        addSpot();
}

void delSpot(void)  //ɾ���ص�
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("��ͼ�����κεص㣬�޷�ɾ����\n");
        return;
    }
    show();
    printf("������Ҫɾ���ĵص��ţ�\n");
    int a;
    scanf("%d", &a);
    while (a > XFD.vn || a < 1)
    {
        printf("����������Ӧλ��1��%d֮�䣬i���������룡\n", XFD.vn);
        scanf("%d", &a);
    }
    printf("Ҫɾ���ĵص�����Ϊ��%s\n�Ƿ�ȷ��ɾ����ȷ��������1 \n", XFD.vex[a - 1].name);
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
    {
        printf("����ɾ���ص�...\n");
        int i, j;
        int count = 0;
        for (i = 0;i < XFD.vn;i++)
            if (XFD.edge[a - 1][i] != INFINITY)
                count++;
        for (i = a - 1;i < XFD.vn;i++)
            XFD.vex[i] = XFD.vex[i + 1];
        for (i = 0;i < XFD.vn;i++)
            for (int j = a - 1;j < XFD.vn;j++)
                XFD.edge[i][j] = XFD.edge[i][j + 1];
        for (i = 0;i < XFD.vn;i++)
            for (j = a - 1;j < XFD.vn;j++)
                XFD.edge[j][i] = XFD.edge[j + 1][i];
        XFD.vn--;
        XFD.en -= count;
    }

    else
        return;

    for (long long i = 0;i < DELAY;i++);
    printf("�ص�ɾ���ɹ���\n");
    printf("�Ƿ����ɾ�������ص㣿��=1����������=�˳�\n");
    int f;
    scanf("%d", &f);
    if (f == 1)
        delSpot();
}

void addPath(void)    //��ӵ�·
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("��ͼ�����κεص㣬������ӵص㣡\n");
        return;
    }
    if (XFD.vn == 1)
    {
        printf("��ǰϵͳ��ֻ��һ���ص㣬�޷���ӵ�·��\n");
        return;
    }
    show();
    if (XFD.en == 0)
        printf("��ǰ��ͼ���޵�·\n");
    else
        printf("Ŀǰ����%d����·\n", XFD.en);
    printf("������Ҫ���ӵ�·�������ص��ţ�\n");
    int a, b;
    scanf("%d %d", &a, &b);
    while (a<1 || a>XFD.vn || b<1 || b>XFD.vn || a == b)
    {
        if (a == b)
            printf("����������ͬ��ţ��������룡\n");
        else
            printf("�����������Ӧλ��1��%d֮�䣬���������룡\n", XFD.vn);
        scanf("%d %d", &a, &b);
    }
    if (XFD.edge[a - 1][b - 1] != INFINITY) {
        printf("%s��%s֮���Ѿ��е�·���޷�����ӣ��볢���޸ĵص���Ϣ������\n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        return;
    }
    else
    {
        int dd;
        printf("������%s��%s֮���·�ĳ��ȣ�\n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        scanf("%d", &dd);
        while (dd <= 0 || dd >= INFINITY)
        {
            printf("��������������������룡\n");
            scanf("%d", &dd);
        }
        printf("������ӵ�·...\n");
        XFD.edge[a - 1][b - 1] = XFD.edge[b - 1][a - 1] = dd;
        XFD.en++;
        for (long long i = 0;i < DELAY;i++);
        printf("�µ�·��ӳɹ���\n");
    }
    printf("�Ƿ��������������·����=1����������=�˳�\n");
    int f;
    scanf("%d", &f);
    if (f == 1)
        addPath();
}

void delPath(void)   //ɾ����·
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("��ͼ�����κεص�\n");
        return;
    }
    if (XFD.en <= 0)
    {
        printf("��ͼ�����κε�·\n");
        return;
    }
    show();
    printf("Ŀǰ����%d����·\n", XFD.en);
    printf("������Ҫɾ����·�������ص��ţ�����������ÿո��������\n");
    int a, b;
    scanf("%d %d", &a, &b);
    while (a<1 || a>XFD.vn || b<1 || b>XFD.en || a == b)
    {
        if (a == b)
            printf("����������ͬ��ţ����������룡\n");
        if (a<1 || a>XFD.vn || b<1 || b>XFD.vn)
            printf("����������Ӧλ��1��%d֮�䣬���������룡\n", XFD.vn);
        scanf("%d %d", &a, &b);
    }
    if (XFD.edge[a - 1][b - 1] >= INFINITY)
    {
        printf("%s��%s֮��û�е�·��\n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        return;
    }
    else
    {
        printf("Ҫɾ������%s��%s֮��ĵ�·���Ƿ�ȷ��ɾ����ȷ��������1 \n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        int flag;
        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("����ɾ����·...\n");
            XFD.edge[a - 1][b - 1] = XFD.edge[b - 1][a - 1] = INFINITY;
            XFD.en--;
            for (long long i = 0;i < DELAY;i++);
            printf("��·ɾ���ɹ���\n");
        }
        else
            return;
    }
    printf("�Ƿ����ɾ��������·����=1����������=�˳�\n");
    int f;
    scanf("%d", &f);
    if (f == 1)
        delPath();
}

void intro(void)   //�ص����
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        if (isAdmin)
            printf("��ͼ�����κεص㣬������ӵص㣡\n");
        else
            printf("��ͼ�����κεص㣬����ϵ��ϵ����Ա��\n");
        return;
    }
    show();
    printf("��������Ҫ��ѯ�ĵص���:");
    int a;
    scanf("%d", &a);
    while (a<1 || a>XFD.vn)
    {
        printf("���������󣬱��Ӧλ��1��%d֮�䣬���������룡\n", XFD.vn);
        scanf("%d", &a);
    }
    printf("%s\n", XFD.vex[a - 1].refer);
    printf("�ٴβ�ѯ������1���������������˳�\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        intro();
}
void Dijkstra(void)   //�����û����ڵص��������ص����
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        if (isAdmin)
            printf("��ͼ�����κεص㣬������ӵص㣡\n");
        else
            printf("��ͼ�����κεص㣬����ϵ����Ա��ӵص㣡\n");
        return;
    }
    if (XFD.vn == 1) {
        printf("��ͼ��ֻ��һ���ص㣬�޷���ѯ��\n");
        return;
    }
    if (XFD.en <= 0)
    {
        if (isAdmin)
            printf("��ͼ���޵�·��������ӵ�·��\n");
        else
            printf("��ͼ���޵�·������ϵ����Ա��ӵ�·��\n");
        return;
    }
    show();
    printf("�����������ڵĵص���:");
    int a;
    scanf("%d", &a);
    while (a<1 || a>XFD.vn)
    {
        printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n", XFD.vn);
        scanf("%d", &a);
    }
    int final[Max];
    int P[Max];
    int D[Max];
    int i, j = 0, k, min, pre;
    final[a - 1] = 1;
    for (int i = 0;i < XFD.vn;i++)
    {
        D[i] = XFD.edge[a - 1][i];
        P[i] = a - 1;
    }
    D[a - 1] = 0;final[a - 1] = 1;P[a - 1] = -1;
    for (i = 1;i < XFD.vn;i++)
    {
        min = INFINITY + 1;
        for (k = 0;k < XFD.vn;k++)
            if (final[k] == 0 && D[k] < min)
            {
                j = k;
                min = D[k];
            }
        final[j] = 1;
        for (k = 0;k < XFD.vn;k++)
            if (final[k] == 0 && (D[j] + XFD.edge[j][k] < D[k]))
            {
                D[k] = D[j] + XFD.edge[j][k];
                P[k] = j;
            }
    }
    int judge = 1;
    for (i = 0;i < XFD.vn;i++)
    {
        if (i != a - 1)
        {
            if (D[i] != INFINITY)
            {
                judge = 0;
                printf("%d�� : %s", D[i], XFD.vex[i].name);
                pre = P[i];
                while (pre >= 0)
                {
                    printf("<-%s", XFD.vex[pre].name);
                    pre = P[pre];
                }
                printf("\n");
            }
        }
    }
    if (judge)
        printf("%s���κεص�䶼û�е�·!\n", XFD.vex[a - 1].name);
    printf("�ٴβ�ѯ������1�������������ּ����˳�\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        Dijkstra();
}



void Floyd(void)   //�����û�ָ���������ص�֮��ľ���
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        if (isAdmin)
            printf("��ͼ�����κεص㣬������ӵص㣡\n");
        else
            printf("��ͼ�����κεص㣬����ϵ����Ա��ӵص㣡\n");
        return;
    }
    if (XFD.vn == 1) {
        printf("��ͼ��ֻ��һ���ص㣬�޷���ѯ��\n");
        return;
    }
    if (XFD.en <= 0)
    {
        if (isAdmin)
            printf("��ͼ���޵�·��������ӵ�·��\n");
        else
            printf("��ͼ���޵�·������ϵ����Ա��ӵ�·��\n");
        return;
    }
    show();
    int path[Max][Max];
    int dist[Max][Max];
    int i, j, k;
    int temp;
    for (int i = 0;i < XFD.vn;i++)
        for (j = 0;j < XFD.vn;j++)
        {
            dist[i][j] = XFD.edge[i][j];
            path[i][j] = j;
        }
    for (k = 0;k < XFD.vn;k++)
        for (i = 0;i < XFD.vn;i++)
            for (j = 0;j < XFD.vn;j++)
            {
                temp = (dist[i][k] == INFINITY || dist[k][j] == INFINITY) ? INFINITY : (dist[i][k] + dist[k][j]);
                if (dist[i][j] > temp)
                {
                    dist[i][j] = temp;
                    path[i][j] = k;
                }
            }
    int a, b;
    printf("��������Ҫ��ѯ֮�����������ص��ţ��м��ÿո������\n");
    scanf("%d %d", &b, &a);
    while (a<1 || a>XFD.vn || b<1 || b>XFD.vn || a == b)
    {
        if (a == b)
            printf("��������������ͬ��ţ��������룡\n");
        else
            printf("�����������������Ŷ�Ӧλ��1��%d֮�䣬�������룡\n", XFD.vn);
        scanf("%d %d", &b, &a);
    }
    if (dist[a - 1][b - 1] == INFINITY)
    {
        printf("%s��%s֮����·����\n", XFD.vex[b - 1].name, XFD.vex[a - 1].name);
    }
    else
    {
        printf("%s��%s�����·������Ϊ��%d��\n", XFD.vex[b - 1].name, XFD.vex[a - 1].name, dist[a - 1][b - 1]);
        printf("·��Ϊ��%s", XFD.vex[b - 1].name);
        if (path[a][b] == b) printf("->%s\n", XFD.vex[a - 1].name);
        else
        {
            k = b - 1;
            while (path[a - 1][k] != k)
            {
                k = path[a - 1][k];
                printf("->%s", XFD.vex[k].name);
            }
            printf("->%s", XFD.vex[a - 1].name);
        }
        printf("\n");
    }
    printf("�ٴβ�ѯ������1�������������ּ����˳�\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        Floyd();
}


class Risk
{
public:
	MGraph X;
	int* danger;
	Risk(MGraph x)
	{
		X = x;
	}
	Risk() {};
	~Risk() {};
	void sortRisk()
	{
		int n = X.vn;
		danger = new int[n];
		for (int i = 0; i < n; i++)
		{
			danger[i] = X.vex[i].num;
		}

		int i, j, k, temp;//k���������±꣬temp����������
		for (i = 0; i < n - 1; ++i)
		{
			k = i;
			for (j = i + 1; j < n; ++j)
				if (X.vex[j].riskLevel < X.vex[k].riskLevel)
					k = j;//��K����¼��С�����±�
			if (k != i)
			{
				temp = danger[k];//�����ŵ���С�������ѭ����һ����������
				danger[k] = danger[i];
				danger[i] = temp;
			}
		}


	}
};