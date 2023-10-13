#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define Max 100 //最大地点数
#define PASSWORD "18cufers" //管理员密码
#define INFINITY 1000000 //路径最大长度
#define DELAY 982337369 //延迟常量
#define CONFIRMATION "QUEREN" //确认码
bool isAdmin; //用户身份
void show(void);//输出所有地点
void Stu(void);//用户系统
void Admin(void);//管理员系统
void intro(void);//地点介绍
void sortRisk(void);//地点风险等级排序
void Dijkstra(void);//查找用户所在地点与其他地点的距离
void Floyd(void);//查找用户指定的两个地点间的最短路径长度
void alter(void);//修改地点信息
void addSpot(void);//添加地点
void delSpot(void);//删除地点
void addPath(void);//添加道路
void delPath(void);//删除道路
void CreateGraph(void); //建立地图

typedef int EdgeType;   //顶点数据类型
typedef struct {
    int num;
    char name[100];
    char refer[1000];
    int riskLevel;  //从1-3分别为低风险小区，中等风险小区，高风险小区
}VexType;

typedef struct {   //邻接矩阵建图
    VexType vex[Max];
    EdgeType edge[Max][Max];
    int vn;//顶点数
    int en;//边数
}MGraph;

static MGraph XFD;  //新发地地图

int flag = 1;

void show(void)//   打印地图信息
{
    printf("当前地图中已经录入的地点有：\n");
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

    strcpy(XFD.vex[0].name, "银地家园");
    strcpy(XFD.vex[0].refer, "小区位于北京市丰台区六圈路与银地西路交叉路口往东约50米(银地花园酒店南侧)，分为A、B、C三个区。");
    strcpy(XFD.vex[1].name, "锦程园");
    strcpy(XFD.vex[1].refer, "小区位于北京市丰台区黄陈路，地处北京四至五环，建筑面积250000平方米，容积率1.02，绿化率25%，主力户型50--120平方米，周边设施较为完善。");
    strcpy(XFD.vex[2].name, "天伦锦城");
    strcpy(XFD.vex[2].refer, "小区位于北京市丰台区黄陈路与市场三街交汇处北行30米路西，地处北京四至五环，2003年建成，建筑面积为430000平方米，绿化率达35%，拥有停车位1824个，周边设施较为匮乏。");
    strcpy(XFD.vex[3].name, "百年小区");
    strcpy(XFD.vex[3].refer, "小区位于北京市丰台区花乡新发地京开高速与京良公路交汇处西北侧，地处北京四至五环，2010年建成，建筑面积为168000平方米，绿化率达31%，拥有停车位1397个。");
    strcpy(XFD.vex[4].name, "风格与林苑");
    strcpy(XFD.vex[4].refer, "小区位于北京市丰台区丰台南路21号，地处北京四至五环，由于在新发地附近，人多容易堵车，一般尽量绕行。");
    strcpy(XFD.vex[5].name, "宜兰园");
    strcpy(XFD.vex[5].refer, "小区位于北京市丰台区京开西路，地处北京四至五环，2002年建成，建筑面积为800000平方米，绿化率达38%，租借停车位150/月。");
    strcpy(XFD.vex[6].name, "天骄俊园");
    strcpy(XFD.vex[6].refer, "小区位于北京市丰台区潘家庙路9号院，地处北京四至五环，2011年建成，建筑面积为267000平方米，绿化率达30%，拥有停车位1837个。");
    strcpy(XFD.vex[7].name, "益辰欣园");
    strcpy(XFD.vex[7].refer, "小区位于北京市丰台区花乡桥南樊羊路88号院，地处北京四至五环，2000年建成，建筑面积为160202平方米，绿化率达36%，拥有停车位600个左右。");
    strcpy(XFD.vex[8].name, "首开华润城");
    strcpy(XFD.vex[8].refer, "小区位于北京市丰台区樊羊路68号院，2015年建成，建筑面积为418000平方米，绿化率达30%，产权70年。");
    strcpy(XFD.vex[9].name, "怡海花园");
    strcpy(XFD.vex[9].refer, "小区位于北京市南四环西路129号，地处北京四至五环，周边配套设施较完善，在第八中学怡海分校对面，交通非常方便，距地铁9号线科怡路地铁站A口很近，步行534米。");
    strcpy(XFD.vex[10].name, "欧亚肿瘤医院");
    strcpy(XFD.vex[10].refer, "北京欧亚肿瘤医院位于北京市丰台区新发地陈留村南口8号，是一所二级肿瘤医院。医院设有肿瘤科、内科、外科、中医科、妇科等。");
    strcpy(XFD.vex[11].name, "新发地妇幼保健院");
    strcpy(XFD.vex[11].refer, "丰台区妇幼保健院始建于1979年，前身为丰台区妇幼保健所，2000年搬迁至马家堡街道，由所改院， 2013年8月迁址至右安门外大街，2017年在丰台南路增设分院，现一院两址，办公面积2.6万平方米，主要业务科室：产科、妇科、儿科、儿童早期综合发展服务中心、健康管理中心、皮肤科、口腔科、乳腺外科等，辅助科室有：功能科、放射科、检验科、药剂科等。");
    strcpy(XFD.vex[12].name, "西鹤年堂中医医院");
    strcpy(XFD.vex[12].refer, "北京西鹤年堂中医医院汇集了来自中日友好医院、中国中医科学院广安门医院、北京市中西医结合医院等70多位专家坐诊，特设肿瘤科、骨伤科、中医内科、心血管科、内分泌科、脾胃病科、肝胆科、呼吸科、妇科、儿科、皮肤科、疼痛门诊、中医外科、口腔科、西医内科、针灸科、推拿科等临床科室。医院现有病床60余张，并配备有手术室及各种先进的临床检验设备，可以满足广大患者的就医需求。北京西鹤年堂中医医院是北京市医保定点机构，无需定点即可持卡就医。医院环境优美，周边交通便利，可为您提供全程优质的医护服务。");
    strcpy(XFD.vex[13].name, "安太嘉园医院");
    strcpy(XFD.vex[13].refer, "医院位于北京丰台嘉园路星河城1号院18号楼，是一所民营/综合医院。医院官方微信平台会定期举行优惠活动，不管是初诊还是复诊，只要在微信平台预约就可以享受一定的优惠待遇，节假日还会抽取幸运好友，赠送安太实物大礼包。");
    strcpy(XFD.vex[14].name, "北京博仁医院");
    strcpy(XFD.vex[14].refer, "医院位于北京市丰台区郑王坟南6号，是一所综合医院，是北京市医保定点医院。医院设有血液内科、儿科、外科、眼科、耳鼻喉科、口腔科、病理科、医学影像科、医学检验科等临床与医技科室。");
    strcpy(XFD.vex[15].name, "北京华军医院");
    strcpy(XFD.vex[15].refer, "中国国际生命医学工程院附属第二医院北京华军中医院，军区医院协作医院，中国儿科医学科学院协作医院，国家中医药局中医专科专病临床基地，北京中科血康血液病医学研究院临床医院，北京市医保定点医院，北京流动人口签约定点医院，设立在我国的首都北京丰台区，是以传统的中医中药为重点开发与研究的临床医院，医院现有占地8亩，建筑面积已经扩建至8000多平米。 医院规模: 北京华军中医院分为综合楼、住院楼、名医堂、神康康复楼四幢楼，现有病房近260张，设有内科、外科、妇产科、儿科、口腔科、中医血液病科、中医心脑血管科、神经康复中心、中医肝胆病科、中医皮肤科、中医骨伤科、中医急诊科、中医康复科中医减肥科、中医肾病科、中医糖尿病专科、中医癫痫科等。");
    strcpy(XFD.vex[16].name, "北京天坛医院");
    strcpy(XFD.vex[16].refer, " 医院位于北京市丰台区南四环西路119号，始建于1956年8月23日，占地面积181581平方米，总建筑面积 352294平方米，是一所以神经外科为先导，以神经科学集群为特色，集医疗、教学、科研、预防为一体的三级甲等综合性医院，是北京市医保定点医院。");
    strcpy(XFD.vex[17].name, "北京众仁堂医院");
    strcpy(XFD.vex[17].refer, "北京丰台众仁堂中医院医院于2009年5月成立，是一家医保定点医院，主要经营范围:内科、外科、妇产科;妇科专业、口腔科、医学检验科;临床体液、血液专业; 临床化学检验专业、医学影像科; X线诊断专业;超声诊断专业;心电诊断专业、中医科;内科专业;妇产科专业;皮肤科专业;骨伤科专业;针灸科专业;推拿科专业;康复医学专业。");
    strcpy(XFD.vex[18].name, "北京时珍堂中医医院");
    strcpy(XFD.vex[18].refer, "医院位于北京市丰台区西南四环的公园对面，与著名的丰台科技园区比邻。医院环境优美，院内绿草荫荫，树木参天，流水潺潺，是北京＊园林式的医院.医院拥有门诊、涉外住院部、体检楼等部门，医疗技术力量雄厚，拥有各种先进的医学诊疗设备。");

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

void alter(void)  //修改地点信息
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("地图中无任何地点，请先添加地点！\n");
        return;
    }
    show();
    int a;
    printf("请输入您要修改信息的地点编号：\n");
    scanf("%d", &a);
    while (a<1 || a>XFD.vn)
    {
        printf("编号输入错误。应位于1到%d之间，请重新输入！\n", XFD.vn);
        scanf("%d", &a);
    }
    int i;
    printf("请输入您需要修改的对象（1.地点名称或简介；2.地点风险等级）：\n");
    scanf("%d", &i);
    if(i==1){
        char newName[100];
        char newRefer[1000];
        printf("地点当前名称为%s,请输入更改后的名称：\n", XFD.vex[a - 1].name);
        scanf("%s", newName);getchar();
        printf("地点当前的简介是：\n%s\n。请输入更改后的简介：\n", XFD.vex[a - 1].refer);
        scanf("%s", newRefer);getchar();
        printf("正在修改地点信息...\n");
        strcpy(XFD.vex[a - 1].name, newName);
        strcpy(XFD.vex[a - 1].refer, newRefer);
        
    }
    
    else if(i==2){
        int newlevel;
        printf("地点当前等级为%d，请输入更改后的风险等级（1-低风险小区，2-中等风险小区，3-高风险小区）：\n", XFD.vex[a - 1].riskLevel);
        scanf("%d", &newlevel);
        printf("正在修改地点信息...\n");
        XFD.vex[a - 1].riskLevel=newlevel;
    }
        
    for (long long i = 0;i < DELAY;i++);
    printf("信息修改成功！\n");
    printf("是否继续更改其他地点信息？是=1，其他数字=退出\n");

    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        alter();
}





void addSpot(void)  //添加地点
{
    //system("clear");
    if (XFD.vn >= Max)
    {
        printf("地图已满，无法再添加新的地点！\n");
        return;
    }
    if (XFD.vn > 0)
        show();
    char newName[100];char newRefer[500];
    printf("请输入需要增加的地点名称：\n");
    scanf("%s", newName);getchar();
    printf("请输入%s的简介（不可多于200字）：\n", newName);
    scanf("%s", newRefer);getchar();

    int m = 0;
    if (XFD.vn >= 1) {
        show();
        printf("请输入新增地点的相邻地点个数：\n");
        scanf("%d", &m);
        while (m<0 || m>XFD.vn) {
            printf("输入错误！相邻地点个数应位于0到%d之间，请重新输入！\n", XFD.vn);
            scanf("%d", &m);
        }
        for (int i = 0;i < m;i++)
        {
            int a, d;
            printf("请输入%s的第%d个相邻地点编号:\n", newName, i + 1);
            scanf("%d", &a);
            while (a<1 || a>XFD.vn || XFD.edge[a - 1][XFD.vn] != INFINITY)
            {
                if (a<1 || a>XFD.vn)
                    printf("编号输入错误。应位于1到%d之间，请重新输入！\n", XFD.vn);
                if (XFD.edge[a - 1][XFD.vn] != INFINITY)
                    printf("请不要重复输入相邻地点，重新输入！\n");
                scanf("%d", &a);
            }
            printf("请输入%s与%s之间的距离:\n", newName, XFD.vex[a - 1].name);
            scanf("%d", &d);
            while (d <= 0 || d >= INFINITY)
            {
                printf("距离输入错误！请重新输入！\n");
                scanf("%d", &d);
            }
            XFD.edge[a - 1][XFD.vn] = XFD.edge[XFD.vn][a - 1] = d;//添加路径长度
        }
    }
    printf("正在添加地点...\n");
    strcpy(XFD.vex[XFD.vn++].name, newName);
    strcpy(XFD.vex[XFD.vn - 1].refer, newRefer);
    XFD.en += m;
    for (long long i = 0;i < DELAY;i++);
    printf("新地点添加成功！\n");
    printf("是否继续增加其他地点？是=1，其他数字=退出\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        addSpot();
}

void delSpot(void)  //删除地点
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("地图中无任何地点，无法删除！\n");
        return;
    }
    show();
    printf("请输入要删除的地点编号：\n");
    int a;
    scanf("%d", &a);
    while (a > XFD.vn || a < 1)
    {
        printf("编号输入错误，应位于1到%d之间，i请重新输入！\n", XFD.vn);
        scanf("%d", &a);
    }
    printf("要删除的地点名称为：%s\n是否确认删除？确认请输入1 \n", XFD.vex[a - 1].name);
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
    {
        printf("正在删除地点...\n");
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
    printf("地点删除成功！\n");
    printf("是否继续删除其他地点？是=1，其他数字=退出\n");
    int f;
    scanf("%d", &f);
    if (f == 1)
        delSpot();
}

void addPath(void)    //添加道路
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("地图中无任何地点，请先添加地点！\n");
        return;
    }
    if (XFD.vn == 1)
    {
        printf("当前系统中只有一个地点，无法添加道路！\n");
        return;
    }
    show();
    if (XFD.en == 0)
        printf("当前地图中无道路\n");
    else
        printf("目前共有%d条道路\n", XFD.en);
    printf("请输入要增加道路的两个地点编号：\n");
    int a, b;
    scanf("%d %d", &a, &b);
    while (a<1 || a>XFD.vn || b<1 || b>XFD.vn || a == b)
    {
        if (a == b)
            printf("请勿输入相同编号，重新输入！\n");
        else
            printf("编号输入有误，应位于1到%d之间，请重新输入！\n", XFD.vn);
        scanf("%d %d", &a, &b);
    }
    if (XFD.edge[a - 1][b - 1] != INFINITY) {
        printf("%s与%s之间已经有道路，无法再添加！请尝试修改地点信息操作。\n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        return;
    }
    else
    {
        int dd;
        printf("请输入%s和%s之间道路的长度：\n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        scanf("%d", &dd);
        while (dd <= 0 || dd >= INFINITY)
        {
            printf("长度输入错误！请重新输入！\n");
            scanf("%d", &dd);
        }
        printf("正在添加道路...\n");
        XFD.edge[a - 1][b - 1] = XFD.edge[b - 1][a - 1] = dd;
        XFD.en++;
        for (long long i = 0;i < DELAY;i++);
        printf("新道路添加成功！\n");
    }
    printf("是否继续增加其他道路？是=1，其他数字=退出\n");
    int f;
    scanf("%d", &f);
    if (f == 1)
        addPath();
}

void delPath(void)   //删除道路
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        printf("地图中无任何地点\n");
        return;
    }
    if (XFD.en <= 0)
    {
        printf("地图中无任何道路\n");
        return;
    }
    show();
    printf("目前共有%d条道路\n", XFD.en);
    printf("请输入要删除道路的两个地点编号（两个编号请用空格隔开）：\n");
    int a, b;
    scanf("%d %d", &a, &b);
    while (a<1 || a>XFD.vn || b<1 || b>XFD.en || a == b)
    {
        if (a == b)
            printf("错误输入相同编号，请重新输入！\n");
        if (a<1 || a>XFD.vn || b<1 || b>XFD.vn)
            printf("编号输入错误，应位于1到%d之间，请重新输入！\n", XFD.vn);
        scanf("%d %d", &a, &b);
    }
    if (XFD.edge[a - 1][b - 1] >= INFINITY)
    {
        printf("%s与%s之间没有道路！\n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        return;
    }
    else
    {
        printf("要删除的是%s与%s之间的道路，是否确认删除？确认请输入1 \n", XFD.vex[a - 1].name, XFD.vex[b - 1].name);
        int flag;
        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("正在删除道路...\n");
            XFD.edge[a - 1][b - 1] = XFD.edge[b - 1][a - 1] = INFINITY;
            XFD.en--;
            for (long long i = 0;i < DELAY;i++);
            printf("道路删除成功！\n");
        }
        else
            return;
    }
    printf("是否继续删除其他道路？是=1，其他数字=退出\n");
    int f;
    scanf("%d", &f);
    if (f == 1)
        delPath();
}

void intro(void)   //地点介绍
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        if (isAdmin)
            printf("地图中无任何地点，请先添加地点！\n");
        else
            printf("地图中无任何地点，请联系联系管理员！\n");
        return;
    }
    show();
    printf("请输入您要查询的地点编号:");
    int a;
    scanf("%d", &a);
    while (a<1 || a>XFD.vn)
    {
        printf("编号输入错误，编号应位于1到%d之间，请重新输入！\n", XFD.vn);
        scanf("%d", &a);
    }
    printf("%s\n", XFD.vex[a - 1].refer);
    printf("再次查询请输入1，输入其他数字退出\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        intro();
}
void Dijkstra(void)   //查找用户所在地点与其他地点距离
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        if (isAdmin)
            printf("地图中无任何地点，请先添加地点！\n");
        else
            printf("地图中无任何地点，请联系管理员添加地点！\n");
        return;
    }
    if (XFD.vn == 1) {
        printf("地图中只有一个地点，无法查询！\n");
        return;
    }
    if (XFD.en <= 0)
    {
        if (isAdmin)
            printf("地图中无道路，请先添加道路！\n");
        else
            printf("地图中无道路，请联系管理员添加道路！\n");
        return;
    }
    show();
    printf("请输入您所在的地点编号:");
    int a;
    scanf("%d", &a);
    while (a<1 || a>XFD.vn)
    {
        printf("编号输入有误，编号应位于1～%d之间，重新输入！\n", XFD.vn);
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
                printf("%d米 : %s", D[i], XFD.vex[i].name);
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
        printf("%s与任何地点间都没有道路!\n", XFD.vex[a - 1].name);
    printf("再次查询请输入1，输入其他数字即可退出\n");
    int flag;
    scanf("%d", &flag);
    if (flag == 1)
        Dijkstra();
}



void Floyd(void)   //查找用户指定的两个地点之间的距离
{
    //system("clear");
    if (XFD.vn <= 0)
    {
        if (isAdmin)
            printf("地图中无任何地点，请先添加地点！\n");
        else
            printf("地图中无任何地点，请联系管理员添加地点！\n");
        return;
    }
    if (XFD.vn == 1) {
        printf("地图中只有一个地点，无法查询！\n");
        return;
    }
    if (XFD.en <= 0)
    {
        if (isAdmin)
            printf("地图中无道路，请先添加道路！\n");
        else
            printf("地图中无道路，请联系管理员添加道路！\n");
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
    printf("请输入您要查询之间距离的两个地点编号，中间用空格隔开：\n");
    scanf("%d %d", &b, &a);
    while (a<1 || a>XFD.vn || b<1 || b>XFD.vn || a == b)
    {
        if (a == b)
            printf("请勿输入两个相同编号，重新输入！\n");
        else
            printf("编号输入有误，两个编号都应位于1～%d之间，重新输入！\n", XFD.vn);
        scanf("%d %d", &b, &a);
    }
    if (dist[a - 1][b - 1] == INFINITY)
    {
        printf("%s与%s之间无路径！\n", XFD.vex[b - 1].name, XFD.vex[a - 1].name);
    }
    else
    {
        printf("%s到%s的最短路径长度为：%d米\n", XFD.vex[b - 1].name, XFD.vex[a - 1].name, dist[a - 1][b - 1]);
        printf("路径为：%s", XFD.vex[b - 1].name);
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
    printf("再次查询请输入1，输入其他数字即可退出\n");
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

		int i, j, k, temp;//k用来保存下标，temp用来做交换
		for (i = 0; i < n - 1; ++i)
		{
			k = i;
			for (j = i + 1; j < n; ++j)
				if (X.vex[j].riskLevel < X.vex[k].riskLevel)
					k = j;//用K来记录最小数的下标
			if (k != i)
			{
				temp = danger[k];//将找着的最小数与此轮循环第一个数做交换
				danger[k] = danger[i];
				danger[i] = temp;
			}
		}


	}
};