#include "pages.h"
#include "tools.h"
#include "initools.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

PlayerPage::PlayerPage(MainWindow *mainWindow, QWidget *parent) : QScrollArea(parent)
{
    QGroupBox *attackGroup = new QGroupBox(tr("攻击"));
	QGridLayout *attackLayout = new QGridLayout();
	attackLayout->addWidget(new QLabel("AT"), 0, 0, Qt::AlignRight);
	attackLayout->addWidget(new CustomSpinBox(5, mainWindow), 0, 1);
    attackLayout->addWidget(new QLabel("武器AT"), 2, 0, Qt::AlignRight);
	CustomSpinBox *weaponAT = new CustomSpinBox(6, mainWindow);
	attackLayout->addWidget(weaponAT, 2, 1);
    attackLayout->addWidget(new QLabel("武器"), 1, 0, Qt::AlignRight);
	attackLayout->addWidget(new WeaponComboBox(29, mainWindow, weaponAT), 1, 1);
	attackGroup->setLayout(attackLayout);

    QGroupBox *defenceGroup = new QGroupBox(tr("防御"));
	QGridLayout *defenceLayout = new QGridLayout();
	defenceLayout->addWidget(new QLabel("DF"), 0, 0, Qt::AlignRight);
	defenceLayout->addWidget(new CustomSpinBox(7, mainWindow), 0, 1);
    defenceLayout->addWidget(new QLabel("防具DF"), 2, 0, Qt::AlignRight);
	CustomSpinBox *armorDF = new CustomSpinBox(8, mainWindow);
	defenceLayout->addWidget(armorDF, 2, 1);
    defenceLayout->addWidget(new QLabel("防具"), 1, 0, Qt::AlignRight);
	defenceLayout->addWidget(new ArmorComboBox(30, mainWindow, armorDF), 1, 1);
	defenceGroup->setLayout(defenceLayout);

    QGroupBox *inventoryGroup = new QGroupBox(tr("背包"));
	inventoryGroup->setLayout(new QVBoxLayout());
	for (int i = 13; i <= 27; i += 2)
	{
		inventoryGroup->layout()->addWidget(new ItemComboBox(i, mainWindow));
	}

    QGroupBox *phoneGroup = new QGroupBox(tr("电话"));
	phoneGroup->setLayout(new QVBoxLayout());
	for (int i = 14; i <= 28; i += 2)
	{
		phoneGroup->layout()->addWidget(new PhoneComboBox(i, mainWindow));
	}

    QGroupBox *dBoxAGroup = new QGroupBox(tr("次元箱A"));
	dBoxAGroup->setLayout(new QVBoxLayout());
	for (int i = 331; i <= 340; i++)
	{
		dBoxAGroup->layout()->addWidget(new ItemComboBox(i, mainWindow));
	}

    QGroupBox *dBoxBGroup = new QGroupBox(tr("次元箱B"));
	dBoxBGroup->setLayout(new QVBoxLayout());
	for (int i = 343; i <= 352; i++)
	{
		dBoxBGroup->layout()->addWidget(new ItemComboBox(i, mainWindow));
	}

    QGroupBox *killsGroup = new QGroupBox(tr("杀怪数"));
	QGridLayout *killsLayout = new QGridLayout();
    killsLayout->addWidget(new QLabel("杀怪数"), 0, 0, Qt::AlignRight);
	killsLayout->addWidget(new CustomSpinBox(12, mainWindow), 0, 1);
    killsLayout->addWidget(new QLabel("总数"), 0, 2, Qt::AlignRight);
	killsLayout->addWidget(new CustomSpinBox(232, mainWindow), 0, 3);
    killsLayout->addWidget(new QLabel("废墟"), 1, 0, Qt::AlignRight);
	killsLayout->addWidget(new CustomSpinBox(233, mainWindow), 1, 1);
    killsLayout->addWidget(new QLabel("雪町"), 1, 2, Qt::AlignRight);
	killsLayout->addWidget(new CustomSpinBox(234, mainWindow), 1, 3);
    killsLayout->addWidget(new QLabel("瀑布"), 1, 4, Qt::AlignRight);
	killsLayout->addWidget(new CustomSpinBox(235, mainWindow), 1, 5);
    killsLayout->addWidget(new QLabel("热地"), 1, 6, Qt::AlignRight);
	killsLayout->addWidget(new CustomSpinBox(236, mainWindow), 1, 7);
	killsGroup->setLayout(killsLayout);

    QGroupBox *lastFightGroup = new QGroupBox(tr("上一次战斗"));
	QGridLayout *lastFightLayout = new QGridLayout();
    lastFightLayout->addWidget(new CustomRadioButton(41, tr("饶恕"), mainWindow), 0, 0);
    lastFightLayout->addWidget(new CustomRadioButton(42, tr("逃走"), mainWindow), 0, 1);
    lastFightLayout->addWidget(new CustomRadioButton(43, tr("杀死"), mainWindow), 1, 0);
    lastFightLayout->addWidget(new CustomRadioButton(44, tr("无聊"), mainWindow), 1, 1);
	lastFightGroup->setLayout(lastFightLayout);

	QFormLayout *checkboxLayout = new QFormLayout();
    checkboxLayout->addRow(tr("困难模式"), new CustomCheckBox(37, mainWindow));
    checkboxLayout->addRow(tr("真和平"), new CustomCheckBox(38, mainWindow));
    checkboxLayout->addRow(tr("关闭遭遇战"), new CustomCheckBox(39, mainWindow));
    checkboxLayout->addRow(tr("烹饪了方便面"), new CustomCheckBox(52, mainWindow));
    checkboxLayout->addRow(tr("饶恕了特定怪物"), new CustomCheckBox(58, mainWindow));
    checkboxLayout->addRow(tr("在装备耐用手套时用过击分卡"), new CustomCheckBox(109, mainWindow));
    checkboxLayout->addRow(tr("手持雨伞"), new CustomCheckBox(116, mainWindow));
    checkboxLayout->addRow(tr("废墟屠杀完毕"), new CustomCheckBox(252, mainWindow));
    checkboxLayout->addRow(tr("雪町屠杀完毕"), new CustomCheckBox(253, mainWindow));
    checkboxLayout->addRow(tr("瀑布屠杀完毕"), new CustomCheckBox(254, mainWindow));
    checkboxLayout->addRow(tr("热地屠杀完毕"), new CustomCheckBox(255, mainWindow));
    checkboxLayout->addRow(tr("核心屠杀完毕"), new CustomCheckBox(256, mainWindow));
    checkboxLayout->addRow(tr("吃过食物"), new CustomCheckBox(291, mainWindow));
    checkboxLayout->addRow(tr("在真实验室内部"), new CustomCheckBox(511, mainWindow));
    checkboxLayout->addRow(tr("看过结尾动画"), new CustomCheckBox(530, mainWindow));

	QFormLayout *spinBoxLayout = new QFormLayout();
    spinBoxLayout->addRow(tr("饶恕次数"), new CustomSpinBox(54, mainWindow));
    spinBoxLayout->addRow(tr("逃走次数"), new CustomSpinBox(55, mainWindow));
    spinBoxLayout->addRow(tr("对话跳过次数"), new CustomSpinBox(56, mainWindow));
    spinBoxLayout->addRow(tr("在蜘蛛烘焙坊花费的G"), new CustomSpinBox(90, mainWindow));
    spinBoxLayout->addRow(tr("在好棒冰处花费的G"), new CustomSpinBox(91, mainWindow));
    spinBoxLayout->addRow(tr("在热狗摊花费的G"), new CustomSpinBox(409, mainWindow));

	QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(new QLabel("名字"), 0, 0, Qt::AlignRight);
	mainLayout->addWidget(new CustomLineEdit(1, mainWindow), 0, 1);
    mainLayout->addWidget(new QLabel("剧情进度"), 0, 2, Qt::AlignRight);
	mainLayout->addWidget(new PlotEdit(543, mainWindow), 0, 3);

	mainLayout->addWidget(new QLabel("LV"), 1, 0, Qt::AlignRight);
	mainLayout->addWidget(new CustomSpinBox(2, mainWindow), 1, 1);
	mainLayout->addWidget(new QLabel("fun"), 1, 2, Qt::AlignRight);
	mainLayout->addWidget(new CustomSpinBox(36, mainWindow), 1, 3);

    mainLayout->addWidget(new QLabel("最大HP"), 2, 0, Qt::AlignRight);
	mainLayout->addWidget(new CustomSpinBox(3, mainWindow), 2, 1);

	mainLayout->addWidget(new QLabel("Gold"), 3, 0, Qt::AlignRight);
	mainLayout->addWidget(new CustomSpinBox(11, mainWindow), 3, 1);

	mainLayout->addWidget(new QLabel("EXP"), 4, 0, Qt::AlignRight);
	mainLayout->addWidget(new CustomSpinBox(10, mainWindow), 4, 1);

    mainLayout->addWidget(new QLabel("时间"), 5, 0, Qt::AlignRight);
	mainLayout->addWidget(new TimeEdit(549, mainWindow), 5, 1);
    mainLayout->addWidget(new QLabel("房间"), 5, 2, Qt::AlignRight);
	mainLayout->addWidget(new RoomComboBox(548, mainWindow), 5, 3);

	mainLayout->addWidget(attackGroup, 0, 4, 3, 2);
	mainLayout->addWidget(defenceGroup, 3, 4, 3, 2);
	mainLayout->addWidget(inventoryGroup, 7, 0, 1, 2);
	mainLayout->addWidget(phoneGroup, 7, 2, 1, 2);
	mainLayout->addWidget(dBoxAGroup, 7, 4, 1, 1);
	mainLayout->addWidget(dBoxBGroup, 7, 5, 1, 1);
	mainLayout->addWidget(killsGroup, 8, 0, 1, 4);
	mainLayout->addWidget(lastFightGroup, 8, 4, 1, 2);
	mainLayout->addLayout(checkboxLayout, 9, 0, 1, 2);
	mainLayout->addLayout(spinBoxLayout, 9, 3, 1, 2);

	QWidget *window = new QWidget();
	window->setLayout(mainLayout);
	setWidget(window);
}

BossesPage::BossesPage(MainWindow *mainWindow, QWidget *parent) : QScrollArea(parent)
{
	QGroupBox *floweyGroup = new QGroupBox(QString("Flowey"));
	QFormLayout *floweyLayout = new QFormLayout();
    floweyLayout->addRow(tr("Flowey跟踪次数"), new CustomSpinBox(40, mainWindow));
    floweyLayout->addRow(tr("杀死了Flowey"), new CustomCheckBox(506, mainWindow));
	floweyGroup->setLayout(floweyLayout);

	QGroupBox *torielGroup = new QGroupBox(QString("Toriel"));
	QFormLayout *torielLayout = new QFormLayout();
    torielLayout->addRow(tr("狗吃掉了Toriel的电话"), new CustomComboBox(68, mainWindow));
    torielLayout->addRow(tr("选择\"说你好\"次数"), new CustomSpinBox(71, mainWindow));
    torielLayout->addRow(tr("对Toriel调情过"), new CustomCheckBox(72, mainWindow));
    torielLayout->addRow(tr("叫过Toriel妈妈"), new CustomCheckBox(73, mainWindow));
    torielLayout->addRow(tr("与Toriel的互动"), new CustomComboBox(76, mainWindow));
    torielLayout->addRow(tr("选择了派的口味"), new CustomComboBox(77, mainWindow));
    torielLayout->addRow(tr("与Toriel聊天次数(真结局)"), new CustomSpinBox(222, mainWindow));
    torielLayout->addRow(tr("看Toriel的短信次数"), new CustomSpinBox(317, mainWindow));
    torielLayout->addRow(tr("当前来自Toriel的短信"), new CustomSpinBox(318, mainWindow));
	torielGroup->setLayout(torielLayout);

	QGroupBox *sansGroup = new QGroupBox(QString("sans"));
	QFormLayout *sansLayout = new QFormLayout();
    sansLayout->addRow(tr("sans在雪镇森林出现前"), new CustomComboBox(78, mainWindow));
    sansLayout->addRow(tr("与sans在Grillby's的约会"), new CustomComboBox(120, mainWindow));
    sansLayout->addRow(tr("与sans聊天次数(真结局)"), new CustomSpinBox(223, mainWindow));
    sansLayout->addRow(tr("与sans战斗过"), new CustomCheckBox(302, mainWindow));
    sansLayout->addRow(tr("尝试过饶恕sans"), new CustomCheckBox(303, mainWindow));
    sansLayout->addRow(tr("在Grillby's点的食物"), new CustomComboBox(422, mainWindow));
    sansLayout->addRow(tr("与sans在MTT酒店的约会"), new CustomComboBox(444, mainWindow));
    sansLayout->addRow(tr("拿到了sans的房间钥匙"), new CustomComboBox(528, mainWindow));
	sansGroup->setLayout(sansLayout);

	QGroupBox *papyrusGroup = new QGroupBox(QString("Papyrus"));
	QFormLayout *papyrusLayout = new QFormLayout();
    papyrusLayout->addRow(tr("对Papyrus调情过"), new CustomCheckBox(97, mainWindow));
    papyrusLayout->addRow(tr("与Papyrus的互动"), new CustomComboBox(98, mainWindow));
    papyrusLayout->addRow(tr("与Papyrus战斗过"), new CustomCheckBox(99, mainWindow));
    papyrusLayout->addRow(tr("与Papyrus的约会"), new CustomComboBox(119, mainWindow));
    papyrusLayout->addRow(tr("与Papyrus聊天次数(真结局)"), new CustomSpinBox(226, mainWindow));
    papyrusLayout->addRow(tr("跳过了Papyrus的特殊攻击(屠杀线)"), new CustomCheckBox(321, mainWindow));
    papyrusLayout->addRow(tr("跳过了电击迷宫(屠杀线)"), new CustomCheckBox(322, mainWindow));
    papyrusLayout->addRow(tr("和Papyrus通过电话"), new CustomSpinBox(493, mainWindow));
	papyrusGroup->setLayout(papyrusLayout);

	QGroupBox *undyneGroup = new QGroupBox(QString("Undyne"));
	QFormLayout *undyneLayout = new QFormLayout();
    undyneLayout->addRow(tr("与Undyne战斗次数"), new CustomSpinBox(130, mainWindow));
    undyneLayout->addRow(tr("与Undyne聊天次数(真结局)"), new CustomSpinBox(224, mainWindow));
    undyneLayout->addRow(tr("让你去和Napstablook聊天(真结局)"), new CustomCheckBox(225, mainWindow));
    undyneLayout->addRow(tr("杀死了Undyne the Undying"), new CustomCheckBox(282, mainWindow));
    undyneLayout->addRow(tr("Undyne在第一次追逐战长时间未命中"), new CustomCheckBox(315, mainWindow));
    undyneLayout->addRow(tr("Undyne在第二次追逐战长时间未命中"), new CustomCheckBox(316, mainWindow));
    undyneLayout->addRow(tr("与Undyne的互动"), new CustomComboBox(381, mainWindow));
    undyneLayout->addRow(tr("Undyne的剩余HP"), new CustomSpinBox(382, mainWindow));
    undyneLayout->addRow(tr("从Undyne的战斗中逃回瀑布"), new CustomCheckBox(383, mainWindow));
    undyneLayout->addRow(tr("与Undyne的约会"), new CustomComboBox(420, mainWindow));
    undyneLayout->addRow(tr("Undyne搬到了Papyrus家"), new CustomCheckBox(496, mainWindow));
    undyneLayout->addRow(tr("Undyne聊起过天气"), new CustomCheckBox(501, mainWindow));
    undyneLayout->addRow(tr("与Undyne的信的互动"), new CustomComboBox(525, mainWindow));
	undyneGroup->setLayout(undyneLayout);

	QGroupBox *alphysGroup = new QGroupBox(QString("Alphys"));
	QFormLayout *alphysLayout = new QFormLayout();
    alphysLayout->addRow(tr("与Alphys聊天次数(真结局)"), new CustomSpinBox(227, mainWindow));
    alphysLayout->addRow(tr("可以和Alphys约会"), new CustomCheckBox(523, mainWindow));
    alphysLayout->addRow(tr("与Alphys的互动"), new CustomComboBox(524, mainWindow));
	alphysGroup->setLayout(alphysLayout);

	QGroupBox *mettatonGroup = new QGroupBox(QString("Mettaton"));
	QFormLayout *mettatonLayout = new QFormLayout();
    mettatonLayout->addRow(tr("与Mettaton聊天次数(真结局)"), new CustomSpinBox(229, mainWindow));
    mettatonLayout->addRow(tr("完成了彩砖谜题"), new CustomCheckBox(309, mainWindow));
    mettatonLayout->addRow(tr("解除炸弹失败"), new CustomCheckBox(319, mainWindow));
    mettatonLayout->addRow(tr("踩到了绿色砖块"), new CustomCheckBox(320, mainWindow));
    mettatonLayout->addRow(tr("射击模式可开启状态"), new CustomComboBox(416, mainWindow));
    mettatonLayout->addRow(tr("让Mettaton转过身"), new CustomComboBox(455, mainWindow));
    mettatonLayout->addRow(tr("杀死了Mettaton"), new CustomCheckBox(456, mainWindow));
	mettatonGroup->setLayout(mettatonLayout);

	QGroupBox *asgoreGroup = new QGroupBox(QString("Asgore"));
	QFormLayout *asgoreLayout = new QFormLayout();
    asgoreLayout->addRow(tr("与Asgore聊天次数(真结局)"), new CustomSpinBox(228, mainWindow));
    asgoreLayout->addRow(tr("杀死了Asgore"), new CustomCheckBox(507, mainWindow));
	asgoreGroup->setLayout(asgoreLayout);

	QGroupBox *asrielGroup = new QGroupBox(QString("Asriel"));
	QFormLayout *asrielLayout = new QFormLayout();
    asrielLayout->addRow(tr("与Asriel战斗中"), new CustomCheckBox(531, mainWindow));
    asrielLayout->addRow(tr("最终战斗阶段"), new CustomComboBox(532, mainWindow));
    asrielLayout->addRow(tr("灵魂重生次数"), new CustomSpinBox(533, mainWindow));
    asrielLayout->addRow(tr("使用过梦想"), new CustomCheckBox(534, mainWindow));
    asrielLayout->addRow(tr("Asriel战斗回合数"), new CustomSpinBox(535, mainWindow));
    asrielLayout->addRow(tr("拯救了Undyne"), new CustomCheckBox(536, mainWindow));
    asrielLayout->addRow(tr("拯救了Alphys"), new CustomCheckBox(537, mainWindow));
    asrielLayout->addRow(tr("拯救了Papyrus和sans"), new CustomCheckBox(538, mainWindow));
    asrielLayout->addRow(tr("拯救了Toriel和Asgore"), new CustomCheckBox(539, mainWindow));
    asrielLayout->addRow(tr("HP显示"), new CustomComboBox(540, mainWindow));
    asrielLayout->addRow(tr("与废墟的Asriel聊天次数"), new CustomSpinBox(542, mainWindow));
	asrielGroup->setLayout(asrielLayout);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addWidget(floweyGroup);
	mainLayout->addWidget(torielGroup);
	mainLayout->addWidget(sansGroup);
	mainLayout->addWidget(papyrusGroup);
	mainLayout->addWidget(undyneGroup);
	mainLayout->addWidget(alphysGroup);
	mainLayout->addWidget(mettatonGroup);
	mainLayout->addWidget(asgoreGroup);
	mainLayout->addWidget(asrielGroup);

	QWidget *window = new QWidget();
	window->setLayout(mainLayout);
	setWidget(window);
}

MonstersPage::MonstersPage(MainWindow *mainWindow, QWidget *parent) : QScrollArea(parent)
{
	QFormLayout *leftLayout = new QFormLayout();
    leftLayout->addRow(tr("与第一个人偶的互动"), new CustomComboBox(45, mainWindow));
    leftLayout->addRow(tr("可饶恕怪物名字颜色"), new CustomComboBox(53, mainWindow));
    leftLayout->addRow(tr("与Doggo的互动"), new CustomComboBox(83, mainWindow));
    leftLayout->addRow(tr("与Dogamy和Dogaressa的互动"), new CustomComboBox(84, mainWindow));
    leftLayout->addRow(tr("与Greater Dog的互动"), new CustomComboBox(85, mainWindow));
    leftLayout->addRow(tr("与Lesser Dog的互动"), new CustomComboBox(86, mainWindow));
    leftLayout->addRow(tr("与Snowman的互动"), new CustomComboBox(87, mainWindow));
    leftLayout->addRow(tr("与Snowdrake的互动"), new CustomComboBox(88, mainWindow));
    leftLayout->addRow(tr("在移除Gyftrot的礼物后又添加礼物"), new CustomCheckBox(105, mainWindow));
    leftLayout->addRow(tr("与Shyren的互动"), new CustomComboBox(112, mainWindow));
    leftLayout->addRow(tr("与Monster Kid的互动"), new CustomComboBox(122, mainWindow));
    leftLayout->addRow(tr("Monster Kid在桥上绊倒"), new CustomComboBox(129, mainWindow));
    leftLayout->addRow(tr("饶恕了Froggit"), new CustomCheckBox(161, mainWindow));
    leftLayout->addRow(tr("饶恕了Whimsun"), new CustomCheckBox(162, mainWindow));
    leftLayout->addRow(tr("饶恕了Moldsmal"), new CustomCheckBox(163, mainWindow));
    leftLayout->addRow(tr("饶恕了Loox"), new CustomCheckBox(164, mainWindow));
    leftLayout->addRow(tr("饶恕了Vegetoid"), new CustomCheckBox(165, mainWindow));
    leftLayout->addRow(tr("饶恕了Migosp"), new CustomCheckBox(166, mainWindow));
    leftLayout->addRow(tr("饶恕了Snowdrake"), new CustomCheckBox(167, mainWindow));
    leftLayout->addRow(tr("饶恕了Ice Cap"), new CustomCheckBox(168, mainWindow));
    leftLayout->addRow(tr("饶恕了Gyftrot"), new CustomCheckBox(169, mainWindow));
    leftLayout->addRow(tr("饶恕了Doggo"), new CustomCheckBox(170, mainWindow));
    leftLayout->addRow(tr("饶恕了Dogamy和Dogaressa"), new CustomCheckBox(171, mainWindow));
    leftLayout->addRow(tr("饶恕了Lesser Dog"), new CustomCheckBox(172, mainWindow));
    leftLayout->addRow(tr("饶恕了Greater Dog"), new CustomCheckBox(173, mainWindow));
    leftLayout->addRow(tr("饶恕了Aaron"), new CustomCheckBox(174, mainWindow));
    leftLayout->addRow(tr("饶恕了Moldbygg"), new CustomCheckBox(175, mainWindow));
    leftLayout->addRow(tr("饶恕了Woshua"), new CustomCheckBox(176, mainWindow));
    leftLayout->addRow(tr("饶恕了Temmie"), new CustomCheckBox(177, mainWindow));
    leftLayout->addRow(tr("饶恕了Mad Dummy"), new CustomCheckBox(178, mainWindow));
    leftLayout->addRow(tr("饶恕了Vulkin"), new CustomCheckBox(179, mainWindow));
    leftLayout->addRow(tr("饶恕了Tsunderplane"), new CustomCheckBox(180, mainWindow));
    leftLayout->addRow(tr("饶恕了Pyrope"), new CustomCheckBox(181, mainWindow));
    leftLayout->addRow(tr("饶恕了Final Froggit"), new CustomCheckBox(182, mainWindow));
    leftLayout->addRow(tr("饶恕了Whimsalot"), new CustomCheckBox(183, mainWindow));
    leftLayout->addRow(tr("饶恕了Astigmatism"), new CustomCheckBox(184, mainWindow));
    leftLayout->addRow(tr("饶恕了Madjick"), new CustomCheckBox(185, mainWindow));
    leftLayout->addRow(tr("饶恕了Knight Knight"), new CustomCheckBox(186, mainWindow));
    leftLayout->addRow(tr("饶恕了Endogeny"), new CustomCheckBox(187, mainWindow));
    leftLayout->addRow(tr("杀死了Glad Dummy"), new CustomCheckBox(283, mainWindow));
    leftLayout->addRow(tr("与Snowman的互动(屠杀线)"), new CustomComboBox(284, mainWindow));
    leftLayout->addRow(tr("与So Sorry的互动"), new CustomComboBox(312, mainWindow));
    leftLayout->addRow(tr("与Glyde战斗"), new CustomCheckBox(313, mainWindow));
    leftLayout->addRow(tr("杀死了皇家守卫"), new CustomCheckBox(433, mainWindow));

	QVBoxLayout *rightLayout = new QVBoxLayout();

	QGroupBox *napstablookGroup = new QGroupBox(QString("Napstablook"));
	QFormLayout *napstablookLayout = new QFormLayout();
    napstablookLayout->addRow(tr("遇到Napstablook"), new CustomComboBox(67, mainWindow));
    napstablookLayout->addRow(tr("与Napstablook的约会"), new CustomComboBox(124, mainWindow));
    napstablookLayout->addRow(tr("用幽灵音乐吓到了Aaron和Woshua"), new CustomCheckBox(126, mainWindow));
    napstablookLayout->addRow(tr("与Napstablook聊天次数(真结局)"), new CustomSpinBox(230, mainWindow));
    napstablookLayout->addRow(tr("NAPSTABLOOK22向你发送过好友申请"), new CustomCheckBox(440, mainWindow));
    napstablookLayout->addRow(tr("和Napstablook一起躺在地上"), new CustomCheckBox(489, mainWindow));
	napstablookGroup->setLayout(napstablookLayout);
	rightLayout->addWidget(napstablookGroup);

	QGroupBox *temmieGroup = new QGroupBox(QString("Temmie"));
	QFormLayout *temmieLayout = new QFormLayout();
    temmieLayout->addRow(tr("Temmie商店倒数"), new CustomSpinBox(296, mainWindow));
    temmieLayout->addRow(tr("Temmie商店特殊出售"), new CustomCheckBox(297, mainWindow));
    temmieLayout->addRow(tr("与过敏的Temmie说过话"), new CustomCheckBox(300, mainWindow));
    temmieLayout->addRow(tr("送tem上大鞋"), new CustomCheckBox(307, mainWindow));
	temmieGroup->setLayout(temmieLayout);
	rightLayout->addWidget(temmieGroup);

	QGroupBox *muffetGroup = new QGroupBox(QString("Muffet"));
	QFormLayout *muffetLayout = new QFormLayout();
    muffetLayout->addRow(tr("Muffet索贿金额"), new CustomSpinBox(413, mainWindow));
    muffetLayout->addRow(tr("用于贿赂Muffet的总金额"), new CustomSpinBox(414, mainWindow));
    muffetLayout->addRow(tr("Muffet战前对话"), new CustomComboBox(427, mainWindow));
    muffetLayout->addRow(tr("杀死了Muffet"), new CustomCheckBox(428, mainWindow));
	muffetGroup->setLayout(muffetLayout);
	rightLayout->addWidget(muffetGroup);

	QGroupBox *riverPersonGroup = new QGroupBox(QString("River Person"));
	QFormLayout *riverPersonLayout = new QFormLayout();
    riverPersonLayout->addRow(tr("River Person的目的地"), new CustomComboBox(490, mainWindow));
    riverPersonLayout->addRow(tr("乘船次数"), new CustomSpinBox(491, mainWindow));
    riverPersonLayout->addRow(tr("River Person的船头是一只狗"), new CustomCheckBox(492, mainWindow));
	riverPersonGroup->setLayout(riverPersonLayout);
	rightLayout->addWidget(riverPersonGroup);

	rightLayout->addStretch();

	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);

	QWidget *window = new QWidget();
	window->setLayout(mainLayout);
	setWidget(window);
}

LocationsPage::LocationsPage(MainWindow *mainWindow, QWidget *parent) : QScrollArea(parent)
{
    QGroupBox *ruinsGroup = new QGroupBox(QString("废墟"));
	QFormLayout *ruinsLayout = new QFormLayout();
    ruinsLayout->addRow(tr("遇到了第一只Froggit"), new CustomCheckBox(61, mainWindow));
    ruinsLayout->addRow(tr("推过第一块石头"), new CustomCheckBox(66, mainWindow));
    ruinsLayout->addRow(tr("推过第二块石头"), new CustomCheckBox(63, mainWindow));
    ruinsLayout->addRow(tr("推过第三块石头"), new CustomCheckBox(62, mainWindow));
    ruinsLayout->addRow(tr("请求第四块石头移动过"), new CustomCheckBox(64, mainWindow));
    ruinsLayout->addRow(tr("拿走的怪物糖果"), new CustomComboBox(65, mainWindow));
    ruinsLayout->addRow(tr("柱子开关开启数"), new CustomSpinBox(74, mainWindow));
    ruinsLayout->addRow(tr("尝试进入地下室次数"), new CustomSpinBox(75, mainWindow));
    ruinsLayout->addRow(tr("了解到关于水香肠的知识"), new CustomCheckBox(81, mainWindow));
    ruinsLayout->addRow(tr("错误的柱子开关开启数"), new CustomSpinBox(82, mainWindow));
    ruinsLayout->addRow(tr("拿到了褪色的丝带"), new CustomCheckBox(131, mainWindow));
    ruinsLayout->addRow(tr("拿到了玩具刀"), new CustomCheckBox(133, mainWindow));
    ruinsLayout->addRow(tr("拿到了派"), new CustomComboBox(134, mainWindow));
	ruinsGroup->setLayout(ruinsLayout);

    QGroupBox *snowdinGroup = new QGroupBox(QString("雪町"));
	QFormLayout *snowdinLayout = new QFormLayout();
    snowdinLayout->addRow(tr("哪个谜题更难"), new CustomComboBox(89, mainWindow));
    snowdinLayout->addRow(tr("Papyrus问过意面陷阱"), new CustomComboBox(93, mainWindow));
    snowdinLayout->addRow(tr("XO谜题重置次数"), new CustomSpinBox(94, mainWindow));
    snowdinLayout->addRow(tr("开关藏在雪下"), new CustomComboBox(95, mainWindow));
    snowdinLayout->addRow(tr("在雪澎里找到30G"), new CustomCheckBox(96, mainWindow));
    snowdinLayout->addRow(tr("森林遭遇战次数"), new CustomSpinBox(101, mainWindow));
    snowdinLayout->addRow(tr("雪町旅馆互动"), new CustomComboBox(103, mainWindow));
    snowdinLayout->addRow(tr("在雪町旅馆住过"), new CustomCheckBox(104, mainWindow));
    snowdinLayout->addRow(tr("在水槽发现Annoying Dog"), new CustomCheckBox(113, mainWindow));
    snowdinLayout->addRow(tr("在沙发里找到20G"), new CustomCheckBox(114, mainWindow));
    snowdinLayout->addRow(tr("看过sans的谜题"), new CustomCheckBox(285, mainWindow));
    snowdinLayout->addRow(tr("在商店里偷窃过(屠杀线)"), new CustomCheckBox(286, mainWindow));
    snowdinLayout->addRow(tr("在作者房间里尝试抚摸狗"), new CustomCheckBox(292, mainWindow));
    snowdinLayout->addRow(tr("落下的树枝已折断"), new CustomComboBox(306, mainWindow));
    snowdinLayout->addRow(tr("接到过错误号码电话"), new CustomCheckBox(308, mainWindow));
    snowdinLayout->addRow(tr("在约会后检查过Papyrus的厨房"), new CustomCheckBox(314, mainWindow));
    snowdinLayout->addRow(tr("赢得了雪球游戏的最高奖励"), new CustomCheckBox(418, mainWindow));
	snowdinGroup->setLayout(snowdinLayout);

    QGroupBox *waterfallGroup = new QGroupBox(QString("瀑布"));
	QFormLayout *waterfallLayout = new QFormLayout();
    waterfallLayout->addRow(tr("Papyrus打电话时你穿的防具"), new CustomComboBox(106, mainWindow));
    waterfallLayout->addRow(tr("在被问到防具时说谎了"), new CustomCheckBox(107, mainWindow));
    waterfallLayout->addRow(tr("Undyne攻击时你穿的防具"), new CustomComboBox(108, mainWindow));
    waterfallLayout->addRow(tr("在瀑布和好棒冰小哥说过话"), new CustomCheckBox(110, mainWindow));
    waterfallLayout->addRow(tr("击分卡数量"), new CustomSpinBox(111, mainWindow));
    waterfallLayout->addRow(tr("在雕像上方放置雨伞"), new CustomCheckBox(117, mainWindow));
    waterfallLayout->addRow(tr("在雨中遇到Monster Kid"), new CustomComboBox(121, mainWindow));
    waterfallLayout->addRow(tr("与垃圾场的存档点互动过"), new CustomCheckBox(122, mainWindow));
    waterfallLayout->addRow(tr("幽灵音乐正在播放"), new CustomComboBox(125, mainWindow));
    waterfallLayout->addRow(tr("与Gerson的谈话"), new CustomComboBox(127, mainWindow));
    waterfallLayout->addRow(tr("拿到了被遗弃的蛋派"), new CustomCheckBox(135, mainWindow));
    waterfallLayout->addRow(tr("拿到了旧芭蕾舞裙"), new CustomCheckBox(136, mainWindow));
    waterfallLayout->addRow(tr("拿到了芭蕾舞鞋"), new CustomCheckBox(137, mainWindow));
    waterfallLayout->addRow(tr("神器"), new CustomComboBox(138, mainWindow));
    waterfallLayout->addRow(tr("拿到了太空食品"), new CustomComboBox(139, mainWindow));
    waterfallLayout->addRow(tr("闪光蘑菇全开启"), new CustomCheckBox(301, mainWindow));
    waterfallLayout->addRow(tr("与Clamgirl说过话"), new CustomCheckBox(310, mainWindow));
    waterfallLayout->addRow(tr("与Elder Puzzler的互动"), new CustomComboBox(311, mainWindow));
    waterfallLayout->addRow(tr("与Mad Dummy的互动"), new CustomComboBox(386, mainWindow));
    waterfallLayout->addRow(tr("解开了钢琴谜题"), new CustomCheckBox(387, mainWindow));
    waterfallLayout->addRow(tr("瀑布(第一区域)遭遇战次数"), new CustomSpinBox(388, mainWindow));
    waterfallLayout->addRow(tr("瀑布(第二区域)遭遇战次数"), new CustomSpinBox(389, mainWindow));
    waterfallLayout->addRow(tr("解开了第一个桥花谜题"), new CustomCheckBox(417, mainWindow));
    waterfallLayout->addRow(tr("解锁了Mettaton的房子"), new CustomCheckBox(464, mainWindow));
    waterfallLayout->addRow(tr("从饮水机里接的水"), new CustomSpinBox(471, mainWindow));
    waterfallLayout->addRow(tr("倒在Undyne面前的水"), new CustomSpinBox(472, mainWindow));
    waterfallLayout->addRow(tr("与Onionsan的互动"), new CustomComboBox(527, mainWindow));
	waterfallGroup->setLayout(waterfallLayout);

    QGroupBox *hotlandGroup = new QGroupBox(QString("热地"));
	QFormLayout *hotlandLayout = new QFormLayout();
    hotlandLayout->addRow(tr("拿到了方便面"), new CustomCheckBox(140, mainWindow));
    hotlandLayout->addRow(tr("拿到了焦锅"), new CustomCheckBox(141, mainWindow));
    hotlandLayout->addRow(tr("拿到了彩绘围裙"), new CustomCheckBox(142, mainWindow));
    hotlandLayout->addRow(tr("好冰棒卖光了"), new CustomCheckBox(281, mainWindow));
    hotlandLayout->addRow(tr("在Bratty & Catty偷窃过(屠杀线)"), new CustomCheckBox(287, mainWindow));
    hotlandLayout->addRow(tr("在MTT酒店送出了海茶"), new CustomCheckBox(293, mainWindow));
    hotlandLayout->addRow(tr("在MTT酒店送出了肉桂兔包"), new CustomCheckBox(294, mainWindow));
    hotlandLayout->addRow(tr("在MTT酒店送出了热狗"), new CustomCheckBox(295, mainWindow));
    hotlandLayout->addRow(tr("在MTT酒店住下"), new CustomComboBox(298, mainWindow));
    hotlandLayout->addRow(tr("倒在地上的水"), new CustomSpinBox(384, mainWindow));
    hotlandLayout->addRow(tr("Papyrus在热地入口打过电话"), new CustomComboBox(385, mainWindow));
    hotlandLayout->addRow(tr("喝了一杯水"), new CustomCheckBox(397, mainWindow));
    hotlandLayout->addRow(tr("取消Alphys的电话(屠杀线)"), new CustomCheckBox(398, mainWindow));
    hotlandLayout->addRow(tr("取消Alphys的消息(屠杀线)"), new CustomCheckBox(399, mainWindow));
    hotlandLayout->addRow(tr("当前来自Alphys的消息"), new CustomSpinBox(400, mainWindow));
    hotlandLayout->addRow(tr("关闭了第一组激光"), new CustomCheckBox(402, mainWindow));
    hotlandLayout->addRow(tr("MTT新闻中激光开启"), new CustomCheckBox(403, mainWindow));
    hotlandLayout->addRow(tr("关闭了射击谜题旁的激光"), new CustomCheckBox(404, mainWindow));
    hotlandLayout->addRow(tr("解开了西方的射击谜题"), new CustomCheckBox(405, mainWindow));
    hotlandLayout->addRow(tr("解开了东方的射击谜题"), new CustomCheckBox(406, mainWindow));
    hotlandLayout->addRow(tr("未完成喷气背包小游戏"), new CustomCheckBox(408, mainWindow));
    hotlandLayout->addRow(tr("热狗购买数量"), new CustomSpinBox(410, mainWindow));
    hotlandLayout->addRow(tr("头上的热狗数量"), new CustomSpinBox(411, mainWindow));
    hotlandLayout->addRow(tr("热狗数量达到上限"), new CustomCheckBox(412, mainWindow));
    hotlandLayout->addRow(tr("MTT新闻中的炸弹全解除"), new CustomSpinBox(426, mainWindow));
    hotlandLayout->addRow(tr("当前的电梯层数"), new CustomComboBox(429, mainWindow));
    hotlandLayout->addRow(tr("解开了南方的射击谜题"), new CustomCheckBox(430, mainWindow));
    hotlandLayout->addRow(tr("解开了北方的射击谜题"), new CustomCheckBox(431, mainWindow));
    hotlandLayout->addRow(tr("Undyne提起过精神控制"), new CustomCheckBox(432, mainWindow));
    hotlandLayout->addRow(tr("在Muffet的商店购买了商品"), new CustomCheckBox(434, mainWindow));
    hotlandLayout->addRow(tr("按下了传送带上所有的开关"), new CustomCheckBox(435, mainWindow));
    hotlandLayout->addRow(tr("与Bratty和Catty的谈话"), new CustomComboBox(436, mainWindow));
    hotlandLayout->addRow(tr("与Bratty和Catty谈到Mettaton"), new CustomComboBox(437, mainWindow));
    hotlandLayout->addRow(tr("与Bratty和Catty谈到Alphys"), new CustomComboBox(438, mainWindow));
    hotlandLayout->addRow(tr("热地遭遇战次数"), new CustomSpinBox(439, mainWindow));
    hotlandLayout->addRow(tr("Flamey的挑战"), new CustomComboBox(465, mainWindow));
    hotlandLayout->addRow(tr("与Burger Pants的互动"), new CustomComboBox(466, mainWindow));
    hotlandLayout->addRow(tr("与Burger Pants谈到Mettaton"), new CustomComboBox(467, mainWindow));
    hotlandLayout->addRow(tr("与Burger Pants, Bratty和Catty聊天"), new CustomComboBox(468, mainWindow));
    hotlandLayout->addRow(tr("购买了空枪"), new CustomCheckBox(473, mainWindow));
    hotlandLayout->addRow(tr("购买了牛仔帽"), new CustomCheckBox(474, mainWindow));
    hotlandLayout->addRow(tr("购买了神秘钥匙"), new CustomCheckBox(475, mainWindow));
    hotlandLayout->addRow(tr("购买了脸排"), new CustomCheckBox(476, mainWindow));
	hotlandGroup->setLayout(hotlandLayout);

    QGroupBox *coreGroup = new QGroupBox(QString("核心"));
	QFormLayout *coreLayout = new QFormLayout();
    coreLayout->addRow(tr("从垃圾桶里得到魅力堡"), new CustomCheckBox(143, mainWindow));
    coreLayout->addRow(tr("从垃圾桶里得到100G"), new CustomCheckBox(144, mainWindow));
    coreLayout->addRow(tr("在核心大厅尝试使用电梯"), new CustomCheckBox(445, mainWindow));
    coreLayout->addRow(tr("在核心大厅里向右走"), new CustomCheckBox(446, mainWindow));
    coreLayout->addRow(tr("在第一个十字路口向右走"), new CustomCheckBox(447, mainWindow));
    coreLayout->addRow(tr("在第一个十字路口向上走"), new CustomCheckBox(448, mainWindow));
    coreLayout->addRow(tr("在贤者之路解开了射击谜题"), new CustomCheckBox(449, mainWindow));
    coreLayout->addRow(tr("在战士之路按下了按钮"), new CustomCheckBox(450, mainWindow));
    coreLayout->addRow(tr("在最终的力场前等待了60秒"), new CustomCheckBox(451, mainWindow));
    coreLayout->addRow(tr("在战士之路被伏击次数"), new CustomComboBox(452, mainWindow));
    coreLayout->addRow(tr("核心(第一区域)遭遇战次数"), new CustomSpinBox(454, mainWindow));
    coreLayout->addRow(tr("核心(第二区域)遭遇战次数"), new CustomSpinBox(457, mainWindow));
	coreGroup->setLayout(coreLayout);

    QGroupBox *castleGroup = new QGroupBox(QString("城堡"));
	QFormLayout *castleLayout = new QFormLayout();
    castleLayout->addRow(tr("得到了破旧的匕首"), new CustomCheckBox(145, mainWindow));
    castleLayout->addRow(tr("得到了心形坠饰锁"), new CustomCheckBox(146, mainWindow));
    castleLayout->addRow(tr("长电梯抵达城堡"), new CustomComboBox(462, mainWindow));
    castleLayout->addRow(tr("第一次使用长电梯"), new CustomCheckBox(463, mainWindow));
    castleLayout->addRow(tr("第一名坠落人类的故事"), new CustomComboBox(481, mainWindow));
    castleLayout->addRow(tr("得到了厨房的钥匙"), new CustomCheckBox(483, mainWindow));
    castleLayout->addRow(tr("得到了走廊的钥匙"), new CustomCheckBox(484, mainWindow));
    castleLayout->addRow(tr("新家的锁"), new CustomComboBox(485, mainWindow));
    castleLayout->addRow(tr("听到过的故事段落(厨房)"), new CustomSpinBox(486, mainWindow));
    castleLayout->addRow(tr("听到过的故事段落(走廊)"), new CustomSpinBox(487, mainWindow));
    castleLayout->addRow(tr("还有些事没完成"), new CustomCheckBox(488, mainWindow));
    castleLayout->addRow(tr("真结局对话"), new CustomComboBox(541, mainWindow));
	castleGroup->setLayout(castleLayout);

    QGroupBox *trueLabGroup = new QGroupBox(QString("真实验室"));
	QFormLayout *trueLabLayout = new QFormLayout();
    trueLabLayout->addRow(tr("进入了真实验室大厅"), new CustomCheckBox(510, mainWindow));
    trueLabLayout->addRow(tr("与红色钥匙的互动"), new CustomComboBox(512, mainWindow));
    trueLabLayout->addRow(tr("与蓝色钥匙的互动"), new CustomComboBox(513, mainWindow));
    trueLabLayout->addRow(tr("与绿色钥匙的互动"), new CustomComboBox(514, mainWindow));
    trueLabLayout->addRow(tr("与黄色钥匙的互动"), new CustomComboBox(515, mainWindow));
    trueLabLayout->addRow(tr("与Alphys的对话结束"), new CustomCheckBox(516, mainWindow));
    trueLabLayout->addRow(tr("洗手池互动次数"), new CustomSpinBox(517, mainWindow));
    trueLabLayout->addRow(tr("红色钥匙位置"), new CustomComboBox(518, mainWindow));
    trueLabLayout->addRow(tr("饶恕了Reaper Bird"), new CustomCheckBox(519, mainWindow));
    trueLabLayout->addRow(tr("饶恕了Lemon Bread"), new CustomCheckBox(520, mainWindow));
    trueLabLayout->addRow(tr("打开了通风系统"), new CustomCheckBox(521, mainWindow));
    trueLabLayout->addRow(tr("重启了电梯电源"), new CustomCheckBox(522, mainWindow));
    trueLabLayout->addRow(tr("薯片购买次数"), new CustomSpinBox(526, mainWindow));
	trueLabGroup->setLayout(trueLabLayout);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addWidget(ruinsGroup);
	mainLayout->addWidget(snowdinGroup);
	mainLayout->addWidget(waterfallGroup);
	mainLayout->addWidget(hotlandGroup);
	mainLayout->addWidget(castleGroup);
	mainLayout->addWidget(trueLabGroup);

	QWidget *window = new QWidget();
	window->setLayout(mainLayout);
	setWidget(window);
}

DebugPage::DebugPage(MainWindow *mainWindow, QWidget *parent) : QScrollArea(parent)
{
	QFormLayout *mainLayout = new QFormLayout();
    mainLayout->addRow(tr("杀怪数重设定"), new CustomCheckBox(35, mainWindow));
    mainLayout->addRow(tr("屠杀等级重设定"), new CustomSpinBox(57, mainWindow));
    mainLayout->addRow(tr("台词跳过数重设定"), new CustomCheckBox(59, mainWindow));

	QWidget *window = new QWidget();
	window->setLayout(mainLayout);
	setWidget(window);
}

DogPage::DogPage(MainWindow *mainWindow, QWidget *parent) : QScrollArea(parent)
{
	QFormLayout *mainLayout = new QFormLayout();
    mainLayout->addRow(tr("捐献的G"), new CustomSpinBox(323, mainWindow));
    mainLayout->addRow(tr("捐献阈值"), new CustomSpinBox(324, mainWindow));
    mainLayout->addRow(tr("达到捐献目标"), new CustomSpinBox(325, mainWindow));
    mainLayout->addRow(tr("狗神社升级"), new CustomSpinBox(326, mainWindow));
    mainLayout->addRow(tr("尝试使用捐献箱"), new CustomCheckBox(327, mainWindow));

	QWidget *window = new QWidget();
	window->setLayout(mainLayout);
	setWidget(window);
}

INIPage::INIPage(MainWindow *mainWindow, QWidget *parent) : QScrollArea(parent)
{
	QGridLayout *mainLayout = new QGridLayout();
	mainLayout->addWidget(new QLabel("General"), 0, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 0, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 1, 0, 16, 1);
	mainLayout->addWidget(new VerticalLine(), 1, 4, 16, 1);
	mainLayout->addWidget(new QLabel("BC"), 1, 1);
	mainLayout->addWidget(new IniSpinBox("BC", mainWindow), 1, 2);
    mainLayout->addWidget(new QLabel("用于\"得到一件物品\"奖杯"), 1, 3);
	mainLayout->addWidget(new QLabel("BH"), 2, 1);
	mainLayout->addWidget(new IniCheckBox("BH", mainWindow), 2, 2);
    mainLayout->addWidget(new QLabel("困难模式边界，控制台专用内容"), 2, 3);
	mainLayout->addWidget(new QLabel("BP"), 3, 1);
	mainLayout->addWidget(new IniCheckBox("BP", mainWindow), 3, 2);
    mainLayout->addWidget(new QLabel("和平结局边界，控制台专用内容"), 3, 3);
	mainLayout->addWidget(new QLabel("BW"), 4, 1);
	mainLayout->addWidget(new IniCheckBox("BW", mainWindow), 4, 2);
    mainLayout->addWidget(new QLabel("普通结局边界，控制台专用内容"), 4, 3);
	mainLayout->addWidget(new QLabel("CH"), 5, 1);
	mainLayout->addWidget(new IniCheckBox("CH", mainWindow), 5, 2);
	mainLayout->addWidget(new QLabel("Complete Hard Mode"), 5, 3);
	mainLayout->addWidget(new QLabel("CP"), 6, 1);
	mainLayout->addWidget(new IniCheckBox("CP", mainWindow), 6, 2);
    mainLayout->addWidget(new QLabel("完成了真和平结局"), 6, 3);
	mainLayout->addWidget(new QLabel("Gameover"), 7, 1);
	mainLayout->addWidget(new IniSpinBox("Gameover", mainWindow), 7, 2);
    mainLayout->addWidget(new QLabel("Game Over次数"), 7, 3);
	mainLayout->addWidget(new QLabel("Kills"), 8, 1);
	mainLayout->addWidget(new IniSpinBox("Kills", mainWindow), 8, 2);
    mainLayout->addWidget(new QLabel("杀怪次数"), 8, 3);
	mainLayout->addWidget(new QLabel("Love"), 9, 1);
	mainLayout->addWidget(new IniSpinBox("Love", mainWindow), 9, 2);
    mainLayout->addWidget(new QLabel("LV，读档界面显示"), 9, 3);
	mainLayout->addWidget(new QLabel("Name"), 10, 1);
	mainLayout->addWidget(new IniLineEdit("Name", mainWindow), 10, 2);
    mainLayout->addWidget(new QLabel("你的名字，读档界面显示"), 10, 3);
	mainLayout->addWidget(new QLabel("Room"), 11, 1);
	mainLayout->addWidget(new IniSpinBox("Room", mainWindow), 11, 2);
    mainLayout->addWidget(new QLabel("当前房间，读档界面显示"), 11, 3);
	mainLayout->addWidget(new QLabel("Tale"), 12, 1);
	mainLayout->addWidget(new IniCheckBox("Tale", mainWindow), 12, 2);
    mainLayout->addWidget(new QLabel("听过第一名坠落人类的故事"), 12, 3);
	mainLayout->addWidget(new QLabel("Time"), 13, 1);
	mainLayout->addWidget(new IniSpinBox("Time", mainWindow), 13, 2);
    mainLayout->addWidget(new QLabel("时间，读档界面显示"), 13, 3);
	mainLayout->addWidget(new QLabel("Truth"), 14, 1);
	mainLayout->addWidget(new IniCheckBox("Truth", mainWindow), 14, 2);
    mainLayout->addWidget(new QLabel("(从未被设定)激活\"Activity Level A\"和\"Activity Level B\""), 14, 3);
	mainLayout->addWidget(new QLabel("Won"), 15, 1);
	mainLayout->addWidget(new IniSpinBox("Won", mainWindow), 15, 2);
    mainLayout->addWidget(new QLabel("到达一个普通结局"), 15, 3);
	mainLayout->addWidget(new QLabel("fun"), 16, 1);
	mainLayout->addWidget(new IniSpinBox("fun", mainWindow), 16, 2);
    mainLayout->addWidget(new QLabel("在游戏开始时随机设定的数值"), 16, 3);
	mainLayout->addWidget(new HorizontalLine(), 17, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Flowey"), 18, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 18, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 19, 0, 15, 1);
	mainLayout->addWidget(new VerticalLine(), 19, 4, 15, 1);
	mainLayout->addWidget(new QLabel("AF"), 19, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/AF", mainWindow), 19, 2);
    mainLayout->addWidget(new QLabel("当真实验室开启却去走了普通结局时，在Flowey的结局对话中＋1"), 19, 3);
	mainLayout->addWidget(new QLabel("AK"), 20, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/AK", mainWindow), 20, 2);
    mainLayout->addWidget(new QLabel("当只有Asgore被杀时，在Flowey的结局对话中＋1"), 20, 3);
	mainLayout->addWidget(new QLabel("Alter"), 21, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/Alter", mainWindow), 21, 2);
    mainLayout->addWidget(new QLabel("如果truename为1, IK大于0或者NK大于0，在Flowey的初遇对话中＋1"), 21, 3);
	mainLayout->addWidget(new QLabel("CHANGE"), 22, 1);
	mainLayout->addWidget(new IniSpinBox("Flowey/CHANGE", mainWindow), 22, 2);
    mainLayout->addWidget(new QLabel("当IK为1, 但没有杀怪时设定为1。当CHANGE小于2(如果NK为1, CHANGE必须大于0),但至少杀过一个非Asgore的怪物时，设定为2"), 22, 3);
	mainLayout->addWidget(new QLabel("CK"), 23, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/CK", mainWindow), 23, 2);
    mainLayout->addWidget(new QLabel("(从未被设定) (从未被调用)"), 23, 3);
	mainLayout->addWidget(new QLabel("EX"), 24, 1);
	mainLayout->addWidget(new IniSpinBox("Flowey/EX", mainWindow), 24, 2);
    mainLayout->addWidget(new QLabel("当你至少杀过一个怪物, 但饶恕了Asgore, 没有完成任何约会并且NK为1(或者IK为1)时，在Flowey的结局对话中＋1"), 24, 3);
	mainLayout->addWidget(new QLabel("FloweyExplain1"), 25, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/FloweyExplain1", mainWindow), 25, 2);
    mainLayout->addWidget(new QLabel("第一次饶恕了Toriel，第二次杀了她(或者反过来)。Flowey会解释存档的力量"), 25, 3);
	mainLayout->addWidget(new QLabel("IK"), 26, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/IK", mainWindow), 26, 2);
    mainLayout->addWidget(new QLabel("当你至少杀过一个怪物(如果N为0, IK必须是0)时，在Flowey的结局对话中＋1"), 26, 3);
	mainLayout->addWidget(new QLabel("K"), 27, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/K", mainWindow), 27, 2);
    mainLayout->addWidget(new QLabel("杀死了Flowey"), 27, 3);
	mainLayout->addWidget(new QLabel("Met1"), 28, 1);
	mainLayout->addWidget(new IniSpinBox("Flowey/Met1", mainWindow), 28, 2);
    mainLayout->addWidget(new QLabel("Flowey初遇次数"), 28, 3);
	mainLayout->addWidget(new QLabel("NK"), 29, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/NK", mainWindow), 29, 2);
    mainLayout->addWidget(new QLabel("当你没有杀死任何怪物时，在Flowey的结局对话中＋1"), 29, 3);
	mainLayout->addWidget(new QLabel("SK"), 30, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/SK", mainWindow), 30, 2);
    mainLayout->addWidget(new QLabel("Flowey没有杀死Asgore（Asgore自杀）"), 30, 3);
	mainLayout->addWidget(new QLabel("SPECIALK"), 31, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/SPECIALK", mainWindow), 31, 2);
    mainLayout->addWidget(new QLabel("当\"truename\"为1时，在Flowey的结局对话中＋1"), 31, 3);
	mainLayout->addWidget(new QLabel("alter2"), 32, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/alter2", mainWindow), 32, 2);
    mainLayout->addWidget(new QLabel("当杀死一切后到达废墟尽头(废墟屠杀完毕)时，在Flowey的对话中＋1"), 32, 3);
	mainLayout->addWidget(new QLabel("truename"), 33, 1);
	mainLayout->addWidget(new IniCheckBox("Flowey/truename", mainWindow), 33, 2);
    mainLayout->addWidget(new QLabel("当杀死一切后到达废墟尽头(废墟屠杀完毕)时，在Flowey的对话中＋1"), 33, 3);
	mainLayout->addWidget(new HorizontalLine(), 34, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Toriel"), 35, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 35, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 36, 0, 3, 1);
	mainLayout->addWidget(new VerticalLine(), 36, 4, 3, 1);
	mainLayout->addWidget(new QLabel("Bscotch"), 36, 1);
	mainLayout->addWidget(new IniSpinBox("Toriel/Bscotch", mainWindow), 36, 2);
    mainLayout->addWidget(new QLabel("选择了派的口味。1是奶油糖，2是肉桂"), 36, 3);
	mainLayout->addWidget(new QLabel("TK"), 37, 1);
	mainLayout->addWidget(new IniSpinBox("Toriel/TK", mainWindow), 37, 2);
    mainLayout->addWidget(new QLabel("杀死的次数"), 37, 3);
	mainLayout->addWidget(new QLabel("TS"), 38, 1);
	mainLayout->addWidget(new IniSpinBox("Toriel/TS", mainWindow), 38, 2);
    mainLayout->addWidget(new QLabel("饶恕的次数"), 38, 3);
	mainLayout->addWidget(new HorizontalLine(), 39, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Sans"), 40, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 40, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 41, 0, 12, 1);
	mainLayout->addWidget(new VerticalLine(), 41, 4, 12, 1);
	mainLayout->addWidget(new QLabel("EndMet"), 41, 1);
	mainLayout->addWidget(new IniCheckBox("Sans/EndMet", mainWindow), 41, 2);
    mainLayout->addWidget(new QLabel("（非屠杀路线）在最终长廊开启对话的次数"), 41, 3);
	mainLayout->addWidget(new QLabel("F"), 42, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/F", mainWindow), 42, 2);
    mainLayout->addWidget(new QLabel("战斗过的次数"), 42, 3);
	mainLayout->addWidget(new QLabel("Intro"), 43, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/Intro", mainWindow), 43, 2);
    mainLayout->addWidget(new QLabel("开场攻击后存活次数"), 43, 3);
	mainLayout->addWidget(new QLabel("M1"), 44, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/M1", mainWindow), 44, 2);
    mainLayout->addWidget(new QLabel("雪町初遇次数"), 44, 3);
	mainLayout->addWidget(new QLabel("MeetLv"), 45, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/MeetLv", mainWindow), 45, 2);
    mainLayout->addWidget(new QLabel("接受审判时的LV"), 45, 3);
	mainLayout->addWidget(new QLabel("MeetLv1"), 46, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/MeetLv1", mainWindow), 46, 2);
    mainLayout->addWidget(new QLabel("未杀怪情况下的最终长廊相遇次数"), 46, 3);
	mainLayout->addWidget(new QLabel("MeetLv2"), 47, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/MeetLv2", mainWindow), 47, 2);
    mainLayout->addWidget(new QLabel("杀过怪情况下的最终长廊相遇次数"), 47, 3);
	mainLayout->addWidget(new QLabel("MP"), 48, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/MP", mainWindow), 48, 2);
    mainLayout->addWidget(new QLabel("(从未被调用)在sans给出饶恕选项时＋1"), 48, 3);
	mainLayout->addWidget(new QLabel("Pass"), 49, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/Pass", mainWindow), 49, 2);
    mainLayout->addWidget(new QLabel("暗号任务进度。当MeetLv1大于0时在完成审判后开始＋1"), 49, 3);
	mainLayout->addWidget(new QLabel("SK"), 50, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/SK", mainWindow), 50, 2);
    mainLayout->addWidget(new QLabel("杀死的次数"), 50, 3);
	mainLayout->addWidget(new QLabel("SS"), 51, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/SS", mainWindow), 51, 2);
    mainLayout->addWidget(new QLabel("饶恕的次数"), 51, 3);
	mainLayout->addWidget(new QLabel("SS2"), 52, 1);
	mainLayout->addWidget(new IniSpinBox("Sans/SS2", mainWindow), 52, 2);
    mainLayout->addWidget(new QLabel("在曾饶恕过的情况下重新选择了攻击，有特殊对话"), 52, 3);
	mainLayout->addWidget(new HorizontalLine(), 53, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Papyrus"), 54, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 54, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 56, 0, 4, 1);
	mainLayout->addWidget(new VerticalLine(), 56, 4, 4, 1);
	mainLayout->addWidget(new QLabel("M1"), 56, 1);
	mainLayout->addWidget(new IniSpinBox("Papyrus/M1", mainWindow), 56, 2);
    mainLayout->addWidget(new QLabel("初遇的次数"), 56, 3);
	mainLayout->addWidget(new QLabel("PD"), 57, 1);
	mainLayout->addWidget(new IniSpinBox("Papyrus/PD", mainWindow), 57, 2);
    mainLayout->addWidget(new QLabel("完成约会的次数，会改变读档界面"), 57, 3);
	mainLayout->addWidget(new QLabel("PK"), 58, 1);
	mainLayout->addWidget(new IniSpinBox("Papyrus/PK", mainWindow), 58, 2);
    mainLayout->addWidget(new QLabel("杀死的次数"), 58, 3);
	mainLayout->addWidget(new QLabel("PS"), 59, 1);
	mainLayout->addWidget(new IniSpinBox("Papyrus/PS", mainWindow), 59, 2);
    mainLayout->addWidget(new QLabel("饶恕的次数"), 59, 3);
	mainLayout->addWidget(new HorizontalLine(), 60, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Undyne"), 61, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 61, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 62, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 62, 4, 1, 1);
	mainLayout->addWidget(new QLabel("UD"), 62, 1);
	mainLayout->addWidget(new IniSpinBox("Undyne/UD", mainWindow), 62, 2);
    mainLayout->addWidget(new QLabel("完成约会的次数，会改变读档界面"), 62, 3);
	mainLayout->addWidget(new HorizontalLine(), 63, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Alphys"), 64, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 64, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 65, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 65, 4, 1, 1);
	mainLayout->addWidget(new QLabel("AD"), 65, 1);
	mainLayout->addWidget(new IniSpinBox("Alphys/AD", mainWindow), 65, 2);
    mainLayout->addWidget(new QLabel("完成约会的次数，会改变读档界面"), 65, 3);
	mainLayout->addWidget(new HorizontalLine(), 66, 0, 1, 5);

	mainLayout->addWidget(new QLabel("MTT"), 67, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 67, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 68, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 68, 4, 1, 1);
	mainLayout->addWidget(new QLabel("EssayNo"), 68, 1);
	mainLayout->addWidget(new IniSpinBox("MTT/EssayNo", mainWindow), 68, 2);
    mainLayout->addWidget(new QLabel("提交论文的次数"), 68, 3);
	mainLayout->addWidget(new HorizontalLine(), 69, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Mett"), 70, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 70, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 71, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 71, 4, 1, 1);
	mainLayout->addWidget(new QLabel("O"), 71, 1);
	mainLayout->addWidget(new IniCheckBox("Mett/O", mainWindow), 71, 2);
    mainLayout->addWidget(new QLabel("看过Mettaton的歌剧"), 71, 3);
	mainLayout->addWidget(new HorizontalLine(), 72, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Mettaton"), 73, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 73, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 74, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 74, 4, 1, 1);
	mainLayout->addWidget(new QLabel("BossMet"), 74, 1);
	mainLayout->addWidget(new IniCheckBox("Mettaton/BossMet", mainWindow), 74, 2);
    mainLayout->addWidget(new QLabel("见过MettatonEX"), 74, 3);
	mainLayout->addWidget(new HorizontalLine(), 75, 0, 1, 5);

	mainLayout->addWidget(new QLabel("Asgore"), 76, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 76, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 77, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 77, 4, 1, 1);
	mainLayout->addWidget(new QLabel("KillYou"), 77, 1);
	mainLayout->addWidget(new IniSpinBox("Asgore/KillYou", mainWindow), 77, 2);
    mainLayout->addWidget(new QLabel("你的死亡次数"), 77, 3);
	mainLayout->addWidget(new HorizontalLine(), 78, 0, 1, 5);

	mainLayout->addWidget(new QLabel("FFFFF"), 79, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 79, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 80, 0, 4, 1);
	mainLayout->addWidget(new VerticalLine(), 80, 4, 4, 1);
	mainLayout->addWidget(new QLabel("D"), 80, 1);
	mainLayout->addWidget(new IniSpinBox("FFFFF/D", mainWindow), 80, 2);
    mainLayout->addWidget(new QLabel("你的死亡次数"), 80, 3);
	mainLayout->addWidget(new QLabel("E"), 81, 1);
	mainLayout->addWidget(new IniSpinBox("FFFFF/E", mainWindow), 81, 2);
    mainLayout->addWidget(new QLabel("在Omega Flowey战结束后设定为1。在饶恕或杀死Flowey后设定为2，在结局标题出现时变回0"), 81, 3);
	mainLayout->addWidget(new QLabel("F"), 82, 1);
	mainLayout->addWidget(new IniSpinBox("FFFFF/F", mainWindow), 82, 2);
    mainLayout->addWidget(new QLabel("在Flowey第一次强制关游戏时设定为1，在战斗结束后变回0"), 82, 3);
	mainLayout->addWidget(new QLabel("P"), 83, 1);
	mainLayout->addWidget(new IniSpinBox("FFFFF/P", mainWindow), 83, 2);
    mainLayout->addWidget(new QLabel("在Omega Flowey出现时设定为1。此后每阶段完成＋1"), 83, 3);
	mainLayout->addWidget(new HorizontalLine(), 84, 0, 1, 5);

	mainLayout->addWidget(new QLabel("EndF"), 85, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 85, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 86, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 86, 4, 1, 1);
	mainLayout->addWidget(new QLabel("EndF"), 86, 1);
	mainLayout->addWidget(new IniSpinBox("EndF/EndF", mainWindow), 86, 2);
    mainLayout->addWidget(new QLabel("真结局后出现THE END时设定为1，Flowey提到真重置时设定为2"), 86, 3);
	mainLayout->addWidget(new HorizontalLine(), 87, 0, 1, 5);

	mainLayout->addWidget(new QLabel("F7"), 88, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 88, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 89, 0, 1, 1);
	mainLayout->addWidget(new VerticalLine(), 89, 4, 1, 1);
	mainLayout->addWidget(new QLabel("F7"), 89, 1);
	mainLayout->addWidget(new IniCheckBox("F7/F7", mainWindow), 89, 2);
    mainLayout->addWidget(new QLabel("Asriel战结束。会改变读档界面"), 89, 3);
	mainLayout->addWidget(new HorizontalLine(), 90, 0, 1, 5);

	mainLayout->addWidget(new QLabel("reset"), 91, 0, Qt::AlignCenter);
	mainLayout->addWidget(new HorizontalLine(), 91, 1, 1, 4);
	mainLayout->addWidget(new VerticalLine(), 92, 0, 2, 1);
	mainLayout->addWidget(new VerticalLine(), 92, 4, 2, 1);
	mainLayout->addWidget(new QLabel("reset"), 92, 1);
	mainLayout->addWidget(new IniCheckBox("reset/reset", mainWindow), 92, 2);
    mainLayout->addWidget(new QLabel("在真重置后出现，激活\"Activity Level A\"和\"Activity Level B\""), 92, 3);
	mainLayout->addWidget(new QLabel("s_key"), 93, 1);
	mainLayout->addWidget(new IniCheckBox("reset/s_key", mainWindow), 93, 2);
    mainLayout->addWidget(new QLabel("在赞助者名单弹幕中完全躲开后设定为1，可以打开雪町森林的神秘门"), 93, 3);
	mainLayout->addWidget(new HorizontalLine(), 94, 0, 1, 5);

	QWidget *window = new QWidget();
	window->setLayout(mainLayout);
	setWidget(window);
}
