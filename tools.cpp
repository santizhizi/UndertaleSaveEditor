#include "tools.h"

#include <QHBoxLayout>

CustomLineEdit::CustomLineEdit(int id, MainWindow *mainWindow, QWidget *parent) : QLineEdit(parent), id(id), mw(mainWindow)
{
	if(id == 1)
	{
        setToolTip(tr("如果名字长度>=7,会在旁边显示\"Easy to change, huh?\""));
	}

	connect(this, SIGNAL(textEdited(QString)), this, SLOT(updateSave(QString)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void CustomLineEdit::updateSave(QString text)
{
	mw->saveData.replace(id, text);
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void CustomLineEdit::updateData()
{
	setText(mw->saveData.at(id));
}

CustomComboBox::CustomComboBox(int id, MainWindow *mainWindow, QWidget *parent) : QComboBox(parent), id(id), mw(mainWindow)
{
	switch (id)
	{
	case 45:
        addItem(tr("逃走"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("饶恕"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("无聊"));
		values.append(3);
		indexes.insert(3, 3);

        setToolTip(tr("如果在废墟让怪物无聊而结束战斗，设定为\"%1\"\n"
                      "影响Mad Dummy的台词").arg(itemText(3)));
		break;
	case 53:
        addItem(tr("黄色"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("白色"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("粉色"));
		values.append(2);
		indexes.insert(2, 2);

        setToolTip(tr("如果不是\"%1\", 垃圾场里会有一堆黄色名字").arg(itemText(0)));
		break;
	case 65:
        addItem(tr("没有拿走糖果"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"你拿走了一颗糖果\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"你拿走了更多糖果\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"你拿走了第三颗糖果\""));
		values.append(3);
		indexes.insert(3, 3);
        addItem(tr("\"你拿得太多太快了\""));
		values.append(4);
		indexes.insert(4, 4);

		setToolTip(tr(""));
		break;
	case 67:
        addItem(tr("挡着路"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("没有挡着路"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("在坑里遇到过"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 68:
        addItem(tr("电话没有丢失"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("电话丢失"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"对不起，一只奇怪的狗抢走了我的电话\""));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 76:
        addItem(tr("到达\"家\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("尝试离开废墟"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("战斗"));
		values.append(3);
		indexes.insert(3, 2);
        addItem(tr("杀死"));
		values.append(4);
		indexes.insert(4, 3);
        addItem(tr("饶恕"));
		values.append(5);
		indexes.insert(5, 4);

		setToolTip(tr(""));
		break;
	case 77:
        addItem(tr("肉桂"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("奶油糖"));
		values.append(1);
		indexes.insert(1, 1);

		setToolTip(tr(""));
		break;
	case 78:
        addItem(tr("到达桥头"));
		values.append(-1);
		indexes.insert(-1, 0);
        addItem(tr("没到桥头"));
		values.append(0);
		indexes.insert(0, 1);
        addItem(tr("树枝折断"));
		values.append(2);
		indexes.insert(2, 3);
        addItem(tr("sans黑影出现"));
		values.append(3);
		indexes.insert(3, 4);

		setToolTip(tr(""));
		break;
	case 83:
        addItem(tr("饶恕"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("使用树枝"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 84:
        addItem(tr("饶恕"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("使用树枝"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 85:
        addItem(tr("饶恕"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("使用树枝"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("无聊"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 86:
        addItem(tr("饶恕"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("抚摸"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 87:
        addItem(tr("没有互动"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("拿了一块"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("拿了另一块"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("在他面前吃了一块"));
		values.append(4);
		indexes.insert(4, 3);
        addItem(tr("吃过一块后与他对话"));
		values.append(5);
		indexes.insert(5, 4);

		setToolTip(tr(""));
		break;
	case 88:
        addItem(tr("没有遇到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在讲笑话时发笑"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("杀死"));
		values.append(2);
		indexes.insert(2, 2);

        setToolTip(tr("如果\"%1\", Chilldrakes会出现").arg(itemText(2)));
		break;
	case 89:
        addItem(tr("拼词游戏"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("纵横字谜"));
		values.append(1);
		indexes.insert(1, 1);

		setToolTip(tr(""));
		break;
	case 93:
        addItem(tr("未设定"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("吃了它"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("没碰它"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 95:
        addItem(tr("没有按下"));
		values.append(-1);
		indexes.insert(-1, 0);
        addItem(tr("可以按"));
		values.append(0);
		indexes.insert(0, 1);
        addItem(tr("已经按下"));
		values.append(1);
		indexes.insert(1, 2);

		setToolTip(tr(""));
		break;
	case 98:
        addItem(tr("抓住你三次"));
		values.append(-3);
		indexes.insert(-3, 0);
        addItem(tr("抓住你两次"));
		values.append(-2);
		indexes.insert(-2, 1);
        addItem(tr("抓住你一次"));
		values.append(-1);
		indexes.insert(-1, 2);
        addItem(tr("饶恕"));
		values.append(0);
		indexes.insert(0, 3);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 4);

        setToolTip(tr("如果\"%1\",跳过Papyrus的战斗").arg(itemText(0)));
		break;
	case 103:
        addItem(tr("没有去过"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("付了80G"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("免费入住"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 106:
        addItem(tr("未设定"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("绷带"));
		values.append(4);
		indexes.insert(4, 1);
        addItem(tr("褪色的丝带"));
		values.append(12);
		indexes.insert(12, 2);
        addItem(tr("男子汉头巾"));
		values.append(15);
		indexes.insert(15, 3);
        addItem(tr("旧芭蕾舞裙"));
		values.append(24);
		indexes.insert(24, 4);

		setToolTip(tr(""));
		break;
	case 108:
        addItem(tr("未设定"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("绷带"));
		values.append(4);
		indexes.insert(4, 1);
        addItem(tr("褪色的丝带"));
		values.append(12);
		indexes.insert(12, 2);
        addItem(tr("男子汉头巾"));
		values.append(15);
		indexes.insert(15, 3);
        addItem(tr("旧芭蕾舞裙"));
		values.append(24);
		indexes.insert(24, 4);

		setToolTip(tr(""));
		break;
	case 112:
        addItem(tr("没有遇到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("开了演唱会"));
		values.append(2);
		indexes.insert(2, 2);

        setToolTip(tr("如果\"%1\",你可以学会能用在Knight Knight和Lemon Bread战斗中的歌").arg(itemText(2)));
		break;
	case 119:
        addItem(tr("没有约会"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在房子外"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("在房子里"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("解锁Papyrus的房间"));
		values.append(3);
		indexes.insert(3, 3);
        addItem(tr("完成约会"));
		values.append(4);
		indexes.insert(4, 4);

		setToolTip(tr(""));
		break;
	case 120:
        addItem(tr("没有约会"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("约会开始"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("完成约会"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 121:
        addItem(tr("没有遇到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"你也拿不了伞吗？\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"你给我们拿了一把伞？\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"伞在哪里……？\""));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 122:
        addItem(tr("没有遇到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("谈到Undyne"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("谈到学校的项目"));
		values.append(3);
		indexes.insert(3, 2);
        addItem(tr("谈到老师"));
		values.append(4);
		indexes.insert(4, 3);
        addItem(tr("远望城堡"));
		values.append(6);
		indexes.insert(6, 4);
        addItem(tr("帮你爬上岩壁"));
		values.append(10);
		indexes.insert(10, 5);

        setToolTip(tr("这个数值也在\"与垃圾场的存档点互动\"分类下使用"));
		break;
	case 124:
        addItem(tr("没有约会"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在房子里聊天"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("躺在地板上"));
		values.append(3);
		indexes.insert(3, 2);
        addItem(tr("没有躺在地板上"));
		values.append(9);
		indexes.insert(9, 3);

		setToolTip(tr(""));
		break;
	case 125:
        addItem(tr("没有播放"));
		values.append(0);
		indexes.insert(0, 0);
		addItem(tr("Spooktunes"));
		values.append(1);
		indexes.insert(1, 1);
		addItem(tr("Spookwave"));
		values.append(2);
		indexes.insert(2, 2);
		addItem(tr("Ghouliday Music"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 127:
        addItem(tr("\"徽记\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"徽记的意义(新)\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"预言 (新)\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"预言\""));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 129:
        addItem(tr("你逃走了"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("你帮助了Monster Kid"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("你站在那里看着"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 134:
        addItem(tr("派还没放凉"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("派可以吃了"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("拿了一块派"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 138:
        addItem(tr("\"那是一个神器。\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"神器消失了。\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"你拿了太多的狗。\""));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 139:
        addItem(tr("没有查看冰箱"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("有两块食品"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("有一块食品"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("冰箱是空的"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 284:
        addItem(tr("\"你好。我是一个雪人。我不能移动。\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"我快要什么都不剩了……\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"求求你……停下……\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("(一堆没用的雪。)"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 298:
        addItem(tr("没有入住"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("第一次"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("第二次"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 306:
        addItem(tr("未设定"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("树枝折断"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("影子出现"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 311:
        addItem(tr("没有对话"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("对话过"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("尝试过推箱子"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 312:
        addItem(tr("没有遇到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("饶恕"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 381:
        addItem(tr("给了水"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("杀死"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("饶恕，但没有给水"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 385:
        addItem(tr("没有打电话"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("未知"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("打了电话"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 386:
        addItem(tr("没有互动"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("打了人偶"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("看了一会儿"));
		values.append(2);
		indexes.insert(2, 2);

        setToolTip(tr("Mad Dummy战斗前的台词会因此变动"));
		break;
	case 416:
        addItem(tr("不可开启"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("可开启"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("已开启"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 420:
        addItem(tr("没有约会"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在房子外对话"));
		values.append(3);
		indexes.insert(3, 1);
        addItem(tr("跑去了Papyrus家"));
		values.append(4);
		indexes.insert(4, 2);
        addItem(tr("到了Papyrus家"));
		values.append(5);
		indexes.insert(5, 3);

		setToolTip(tr(""));
		break;
	case 422:
        addItem(tr("无"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("薯条"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("汉堡"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 427:
        addItem(tr("\"你听到他们说什么了吗？\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"他们说一个穿条纹衫的人类……\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"我听说那人类讨厌蜘蛛。\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"我听说那人类喜欢踩碎蜘蛛。\""));
		values.append(3);
		indexes.insert(3, 3);
        addItem(tr("\"我听说那人类喜欢扯掉蜘蛛腿\""));
		values.append(4);
		indexes.insert(4, 4);
        addItem(tr("\"我听说……\""));
		values.append(5);
		indexes.insert(5, 5);

		setToolTip(tr(""));
		break;
	case 429:
        addItem(tr("左1层"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("右1层"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("右2层"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("左2层"));
		values.append(3);
		indexes.insert(3, 3);
        addItem(tr("左3层"));
		values.append(4);
		indexes.insert(4, 4);
        addItem(tr("右3层"));
		values.append(5);
		indexes.insert(5, 5);

		setToolTip(tr(""));
		break;
	case 436:
        addItem(tr("\"关于你们的商品\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"商品来源(新)\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"垃圾的来源(新)\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"垃圾的来源\""));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 437:
        addItem(tr("\"关于Mettaton\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"Mettaton的来源(新)\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"关于Mettaton (旧?\?\?)\""));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 438:
        addItem(tr("\"关于Alphys\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"皇室科学家(新)\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"关于ASGORE(新)\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"关于ASGORE\""));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 444:
        addItem(tr("没有约会"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("约会开始"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("约会结束"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 452:
        addItem(tr("没有到达"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("Whimsalot和Final Froggit"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("Knight Knight和Madjick"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("Final Froggit, Astigmatism和Whimsalot"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 455:
        addItem(tr("没有遇到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("没有转身"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("已经转身"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 462:
        addItem(tr("核心"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("城堡"));
		values.append(1);
		indexes.insert(1, 1);

		setToolTip(tr(""));
		break;
	case 465:
        addItem(tr("没有对话"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("想起了名字"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("忘记了名字"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 466:
        addItem(tr("没有对话"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("买过东西"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("对话过"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	case 467:
		addItem(tr("\"Mettaton\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"为什么Mettaton很坏(新)\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"其他为什么MTT很坏(新)\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"其他为什么MTT很坏\""));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 468:
        addItem(tr("[B.Pants] \"爱情建议\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("[B.Pants] \"魅力堡故事(NEW)\""));
		values.append(1);
		indexes.insert(1, 1);
		addItem(tr("[B&C] \"Burgerpants (NEW)\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("[B&C] \"更多Burgerpants (NEW)\""));
		values.append(4);
		indexes.insert(4, 3);
		addItem(tr("[B.Pants] \"Bratty & Catty (NEW)\""));
		values.append(5);
		indexes.insert(5, 4);
		addItem(tr("[B&C] \"Burgerpants hangout (NEW)\""));
		values.append(6);
		indexes.insert(6, 5);
        addItem(tr("[B&C] \"那种人(NEW)\""));
		values.append(7);
		indexes.insert(7, 6);
        addItem(tr("[B.Pants] \"Catty的邀请(新)\""));
		values.append(8);
		indexes.insert(8, 7);
        addItem(tr("[B.Pants] \"Catty的邀请\""));
		values.append(9);
		indexes.insert(9, 8);

        setToolTip(tr("这些对话发生在两个商店[用方括号标注]"));
		break;
	case 481:
        addItem(tr("\"很久以前，一名人类落入了废墟。\""));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("\"ASRIEL,国王的儿子, 听到了人类的喊声\""));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("\"随着时间的推移，ASRIEL和人类变得情同手足。\""));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("\"然后……某一天……\""));
		values.append(3);
		indexes.insert(3, 3);
        addItem(tr("\"重病的人类只有一个愿望。\""));
		values.append(4);
		indexes.insert(4, 4);
        addItem(tr("\"第二天。\""));
		values.append(5);
		indexes.insert(5, 5);
        addItem(tr("\"沉浸于悲痛之中的ASRIEL,吸收了人类的灵魂。\""));
		values.append(6);
		indexes.insert(6, 6);
        addItem(tr("\"有了人类的灵魂, ASRIEL穿过了屏障。\""));
		values.append(7);
		indexes.insert(7, 7);
        addItem(tr("\"ASRIEL到了村庄的中央。\""));
		values.append(8);
		indexes.insert(8, 8);
        addItem(tr("\"突然传来了尖叫声。\""));
		values.append(9);
		indexes.insert(9, 9);
        addItem(tr("\"人类用一切手段去攻击他。\""));
		values.append(10);
		indexes.insert(10, 10);
        addItem(tr("\"但是……\""));
		values.append(11);
		indexes.insert(11, 11);
        addItem(tr("\"带着重伤, ASRIEL回到了家。\""));
		values.append(12);
		indexes.insert(12, 12);
        addItem(tr("\"王国陷入了绝望。\""));
		values.append(13);
		indexes.insert(13, 13);
        addItem(tr("\"国王决定要终结我们的痛苦。\""));
		values.append(14);
		indexes.insert(14, 14);
        addItem(tr("\"那不会太遥远了。\""));
		values.append(15);
		indexes.insert(15, 15);
        addItem(tr("\"你也应该微笑。\""));
		values.append(16);
		indexes.insert(16, 16);
        addItem(tr("\"你将会得到自由。\""));
		values.append(17);
		indexes.insert(17, 17);

		setToolTip(tr(""));
		break;
	case 485:
        addItem(tr("(道路被两把锁挡住了。)"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("(你需要两把钥匙才能通过。)"));
		values.append(0.5);
		indexes.insert(0.5, 1);
        addItem(tr("(你解开了锁链。)"));
		values.append(1);
		indexes.insert(1, 2);

		setToolTip(tr(""));
		break;
	case 490:
        addItem(tr("热地"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("雪町"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("瀑布"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("热地"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 512:
        addItem(tr("还没有找到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在水池里找到了"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("(挂上了钥匙链)"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("(已解锁)"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 513:
        addItem(tr("还没有找到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在冰箱里找到了"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("(挂上了钥匙链)"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("(已解锁)"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 514:
        addItem(tr("还没有找到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在浴缸里找到了"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("(挂上了钥匙链)"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("(已解锁)"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 515:
        addItem(tr("还没有找到"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("在床单下找到了"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("(挂上了钥匙链)"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("(已解锁)"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 518:
        addItem(tr("还没查看过任何一个洗手池"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("左侧的"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("中间的"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("右侧的"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 524:
        addItem(tr("没有互动"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("可以拿到Undyne的信"));
		values.append(8);
		indexes.insert(8, 1);
        addItem(tr("拿到了Undyne的信"));
		values.append(9);
		indexes.insert(9, 2);
        addItem(tr("完成Alphys的约会"));
		values.append(10);
		indexes.insert(10, 3);
        addItem(tr("接到了Papyrus的电话"));
		values.append(11);
		indexes.insert(11, 4);
        addItem(tr("完成了真实验室"));
		values.append(12);
		indexes.insert(12, 5);

		setToolTip(tr(""));
		break;
	case 525:
        addItem(tr("没有互动"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("丢失了信"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("Undyne的信"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("Undyne的信EX"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 527:
        addItem(tr("Onionsan不想说话"));
		values.append(-1);
		indexes.insert(-1, 0);
        addItem(tr("没有互动"));
		values.append(0);
		indexes.insert(0, 1);
        addItem(tr("\"我是Onionsan!\""));
		values.append(1);
		indexes.insert(1, 2);
        addItem(tr("\"你刚来到瀑布，嗯？\""));
		values.append(2);
		indexes.insert(2, 3);
        addItem(tr("\"虽然这里的水很浅……\""));
		values.append(3);
		indexes.insert(3, 4);
        addItem(tr("\"听着，Undyne会解决一切的！\""));
		values.append(4);
		indexes.insert(4, 5);
        addItem(tr("\"那是这个房间的尽头。\""));
		values.append(5);
		indexes.insert(5, 6);
        addItem(tr("\"是的，我也……\""));
		values.append(6);
		indexes.insert(6, 7);
        addItem(tr("\"我在想我们什么时候能全部自由。\""));
		values.append(7);
		indexes.insert(7, 8);

		setToolTip(tr(""));
		break;
	case 528:
        addItem(tr("没有拿到钥匙"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("拿到钥匙"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("进入sans的房间"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("找到了银色钥匙"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 532:
        addItem(tr("未设定"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("拯救了所有人"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("拯救某个其他人"));
		values.append(2);
		indexes.insert(2, 2);
        addItem(tr("拯救Asriel"));
		values.append(3);
		indexes.insert(3, 3);

		setToolTip(tr(""));
		break;
	case 540:
        addItem(tr("正常"));
		values.append(0);
		indexes.insert(0, 0);
		addItem(tr("\"00.001\""));
		values.append(1);
		indexes.insert(1, 1);
		addItem(tr("\"00.0001\""));
		values.append(2);
		indexes.insert(2, 2);
		addItem(tr("\"00.000001\""));
		values.append(3);
		indexes.insert(3, 3);
		addItem(tr("\"00.0000000001\""));
		values.append(4);
		indexes.insert(4, 4);

		setToolTip(tr(""));
		break;
	case 541:
        addItem(tr("未设定"));
		values.append(0);
		indexes.insert(0, 0);
        addItem(tr("与Asriel对话过"));
		values.append(1);
		indexes.insert(1, 1);
        addItem(tr("与所有人对话过"));
		values.append(2);
		indexes.insert(2, 2);

		setToolTip(tr(""));
		break;
	}

	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void CustomComboBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void CustomComboBox::updateData()
{
	setCurrentIndex(indexes.value(mw->saveData.at(id).toInt()));
}

CustomSpinBox::CustomSpinBox(int id, MainWindow *mainWindow, QWidget *parent) : QSpinBox(parent), id(id), mw(mainWindow)
{
	setRange(INT_MIN, INT_MAX);
	switch (id)
	{
	case 2:
		setRange(1, 20);
		break;
	case 10:
		setRange(0, 99999);
		break;
	case 56:
        setToolTip(tr("如果>5,移除\"四只青蛙\"房间里的一只青蛙"));
		break;
	case 71:
        setToolTip(tr("如果>=4,Toriel的回应不再改变"));
		break;
	case 74:
        setToolTip(tr("如果>25,开关会感到不舒服"));
		break;
	case 75:
        setToolTip(tr("如果>9, Toriel的回应不再改变"));
		break;
	case 82:
        setToolTip(tr("如果2,你会在第二个房间得到关于蓝色开关的暗示"));
		break;
	case 90:
        setToolTip(tr("如果>= 9000,跳过Muffet的战斗\n"
                      "战斗中检查以下数值: >0, >20, >50\n"
                      "NPC对话中检查以下数值: >=1, >=13, >=25, >=40, >=70, >=100, >=9000"));
		break;
	case 94:
        setToolTip(tr("如果>5,改变完成谜题后与sans的对话"));
		break;
	case 101:
		setToolTip(tr("0 = Snowdrake\n"
					  "1 = Ice Cap\n"
                      "2 (如果没有遇到Doggo) = 随机\n"
                      "2 (如果遇到Doggo) = Lesser Dog\n"
                      "4 =随机"));
		break;
	case 232:
        setToolTip(tr("根据一般杀怪数统计"));
		break;
	case 317:
        setToolTip(tr("如果>=17, Toriel不会再发信息"));
		break;
	case 318:
        setToolTip(tr("玩家必须移动到一个新的房间才能收到新的信息"));
		break;
	case 384:
        setToolTip(tr("影响与\"Clamguy\"的对话\n"
                      "如果有一个大水池，在真结局时会长出一棵小树"));
		break;
	case 388:
		setToolTip(tr("0 = Aaron\n"
					  "1 = Woshua\n"
					  "2 = Moldsmal\n"
                      ">2 =随机"));
		break;
	case 389:
		setToolTip(tr("0 = Temmie\n"
                      "1 = Moldsmal和Moldbygg\n"
                      "2 = Woshua和Aaron\n"
                      "3 = Moldbygg和Woshua\n"
                      ">3 =随机"));
		break;
	case 400:
        setToolTip(tr("设定为99时跳过所有信息"));
		break;
	case 439:
		setToolTip(tr("0 = Vulkin\n"
					  "1 = Tsunderplane\n"
					  "2 = Pyrope\n"
                      "3 = Tsunderplane和Vulkin\n"
                      "4 = Pyrope和Pyrope\n"
                      ">4 =随机"));
		break;
	case 454:
        setToolTip(tr("0 = Whimsalot和Final Froggit\n"
                      "1 = Whimsalot和Astigmatism\n"
                      "2 = Knight Knight和Madjick\n"
                      ">2 =随机"));
		break;
	case 457:
		setToolTip(tr("0 = Astigmatism\n"
                      "1 = Whimsalot和Final Froggit\n"
                      "2 = Whimsalot和Astigmatism\n"
                      "3 = Final Froggit和Astigmatism\n"
                      "4 = Knight Knight和Madjick\n"
                      ">4 =随机"));
		break;
	case 493:
        setToolTip(tr("改变房间时重置"));
		break;
	case 517:
        setToolTip(tr("如果等于2, Memoryhead出现\n"
                      "如果等于13, 对话会变成\"你真的很喜欢洗手\""));
		break;
	case 526:
        setToolTip(tr("如果等于8, 自动售货机会变空"));
		break;
	}

	connect(this, SIGNAL(valueChanged(QString)), this, SLOT(updateSave(QString)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void CustomSpinBox::updateSave(QString text)
{
	mw->saveData.replace(id, text);
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void CustomSpinBox::updateData()
{
	setValue(mw->saveData.at(id).toInt());
}

CustomCheckBox::CustomCheckBox(int id, MainWindow *mainWindow, QWidget *parent) : QCheckBox(parent), id(id), mw(mainWindow)
{
	switch (id)
	{
	case 35:
        setToolTip(tr("设定为0可以让Undyne的反应变成你没有杀怪的情况"));
		break;
	case 58:
        setToolTip(tr("影响是否在屠杀线，>=16时触发审判战"));
		break;
	case 59:
        setToolTip(tr("按下C可以瞬间跳过台词"));
		break;
	case 72:
        setToolTip(tr("Toriel会在真结局告诉sans"));
		break;
	case 73:
        setToolTip(tr("Toriel会在真结局告诉sans"));
		break;
	case 117:
        setToolTip(tr("音乐盒开始演奏"));
		break;
	case 122:
        setToolTip(tr("这个数值也在\"与Monster Kid的互动\"分类下使用"));
		break;
	case 281:
        setToolTip(tr("如果皇家守卫已死则为false"));
		break;
	case 286:
        setToolTip(tr("从柜台后拿走758G"));
		break;
	case 287:
        setToolTip(tr("在收银台拿走5G"));
		break;
	case 291:
        setToolTip(tr("sans会在普通结局电话里评论这一点"));
		break;
	case 293:
        setToolTip(tr("奖励99G"));
		break;
	case 294:
        setToolTip(tr("奖励99G"));
		break;
	case 295:
        setToolTip(tr("奖励一个嘘声小狗\n"
                      "提示: 尝试递送热猫,狗狗沙拉或者狗狗残留物"));
		break;
	case 302:
		setToolTip(tr("you're gonna have a bad time"));
		break;
	case 309:
        setToolTip(tr("Papyrus会评论这一项"));
		break;
	case 314:
        setToolTip(tr("取消Glyde遭遇战"));
		break;
	case 315:
        setToolTip(tr("Undyne的长矛攻击变得非常迅速\n"
                      "Monster kid会评价Undyne有多么生气"));
		break;
	case 316:
        setToolTip(tr("Undyne的长矛攻击变得非常迅速"));
		break;
	case 383:
        setToolTip(tr("Undyne会在战斗开始说\"我知道你会回来的！\" "));
		break;
	case 432:
        setToolTip(tr("改变皇家守卫在战斗中的对话"));
		break;
	case 496:
        setToolTip(tr("将 \"Papyrus的电话\"变成\"Papyrus和Undyne\""));
		break;
	case 510:
        setToolTip(tr("开始播放真实验室BGM"));
		break;
	case 511:
        setToolTip(tr("给玩家加上一层光影"));
		break;
	case 516:
        setToolTip(tr("打开日记面板"));
		break;
	}

	connect(this, SIGNAL(stateChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void CustomCheckBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void CustomCheckBox::updateData()
{
	setCheckState(states.value(mw->saveData.at(id).toInt()));
}

CustomRadioButton::CustomRadioButton(int id, QString text, MainWindow *mainWindow, QWidget *parent) : QRadioButton(text, parent), id(id), mw(mainWindow)
{
	switch (id)
	{
	case 44:
        setToolTip(tr("仅在废墟"));
		break;
	}

	connect(this, SIGNAL(toggled(bool)), this, SLOT(updateSave(bool)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void CustomRadioButton::updateSave(bool checked)
{
	mw->saveData.replace(id, QString::number(checked));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void CustomRadioButton::updateData()
{
	setChecked(mw->saveData.at(id).toInt());
}

ItemComboBox::ItemComboBox(int id, MainWindow *mainWindow, QWidget *parent) : QComboBox(parent), id(id), mw(mainWindow)
{
    addItem(tr("无"));
    addItem(tr("怪物糖果"));
    addItem(tr("槌球棍"));
    addItem(tr("树枝"));
    addItem(tr("绷带"));
    addItem(tr("石糖"));
    addItem(tr("南瓜圈"));
    addItem(tr("蜘蛛甜甜圈"));
    addItem(tr("无泪洋葱"));
    addItem(tr("鬼果"));
    addItem(tr("蜘蛛苹果酒"));
    addItem(tr("奶油糖派"));
    addItem(tr("褪色的丝带"));
    addItem(tr("玩具刀"));
    addItem(tr("耐用的手套"));
    addItem(tr("男子汉头巾"));
    addItem(tr("雪人的碎片"));
    addItem(tr("好冰棒"));
    addItem(tr("狗面冰激凌"));
    addItem(tr("情侣棒冰"));
    addItem(tr("单身狗棒冰"));
    addItem(tr("肉桂兔包"));
    addItem(tr("Temmie脆片"));
    addItem(tr("被遗弃的蛋派"));
    addItem(tr("旧芭蕾舞裙"));
    addItem(tr("芭蕾舞鞋"));
    addItem(tr("击分卡"));
    addItem(tr("神烦狗"));
    addItem(tr("狗狗沙拉"));
    addItem(tr("狗狗残留物"));
    addItem(tr("狗狗残留物"));
    addItem(tr("狗狗残留物"));
    addItem(tr("狗狗残留物"));
    addItem(tr("狗狗残留物"));
    addItem(tr("狗狗残留物"));
    addItem(tr("太空食品"));
    addItem(tr("方便面"));
    addItem(tr("螃蟹苹果"));
    addItem(tr("热狗……？"));
    addItem(tr("热猫"));
    addItem(tr("魅力堡"));
    addItem(tr("海茶"));
    addItem(tr("新星芭菲"));
    addItem(tr("传说英雄"));
    addItem(tr("多雾眼镜"));
    addItem(tr("被撕裂的笔记本"));
    addItem(tr("彩绘围裙"));
    addItem(tr("焦锅"));
    addItem(tr("牛仔帽"));
    addItem(tr("空枪"));
    addItem(tr("心形坠饰锁"));
    addItem(tr("破旧的匕首"));
    addItem(tr("真刀"));
    addItem(tr("坠饰锁"));
    addItem(tr("不好的回忆"));
    addItem(tr("梦想"));
    addItem(tr("Undyne的信"));
    addItem(tr("Undyne的信EX"));
    addItem(tr("薯片"));
    addItem(tr("垃圾食品"));
    addItem(tr("神秘钥匙"));
    addItem(tr("脸排"));
    addItem(tr("嘘声小狗"));
    addItem(tr("蜗牛派"));
    addItem(tr("temy甲"));

	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void ItemComboBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(i));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void ItemComboBox::updateData()
{
	setCurrentIndex(mw->saveData.at(id).toInt());
}

PhoneComboBox::PhoneComboBox(int id, MainWindow *mainWindow, QWidget *parent) : QComboBox(parent), id(id), mw(mainWindow)
{
    addItem(tr("无"));
    addItem(tr("说你好"));
    addItem(tr("谜题帮助"));
    addItem(tr("关于你自己"));
    addItem(tr("叫她\"妈妈\""));
    addItem(tr("调情"));
    addItem(tr("Toriel的电话"));
    addItem(tr("Papyrus的电话"));
    addItem(tr("次元箱A"));
    addItem(tr("次元箱B"));

	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void PhoneComboBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void PhoneComboBox::updateData()
{
	setCurrentIndex(indexes.value(mw->saveData.at(id).toInt()));
}

WeaponComboBox::WeaponComboBox(int id, MainWindow *mainWindow, CustomSpinBox *weaponAT, QWidget *parent) : QComboBox(parent), id(id), mw(mainWindow), wat(weaponAT)
{
    addItem(tr("树枝"));
    addItem(tr("玩具刀"));
    addItem(tr("耐用的手套"));
    addItem(tr("芭蕾舞鞋"));
    addItem(tr("被撕裂的笔记本"));
    addItem(tr("焦锅"));
    addItem(tr("空枪"));
    addItem(tr("破旧的匕首"));
    addItem(tr("真刀"));

	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void WeaponComboBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	wat->setValue(atValues[i]);
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void WeaponComboBox::updateData()
{
	setCurrentIndex(indexes.value(mw->saveData.at(id).toInt()));
}

ArmorComboBox::ArmorComboBox(int id, MainWindow *mainWindow, CustomSpinBox *armorDF, QWidget *parent) : QComboBox(parent), id(id), mw(mainWindow), adf(armorDF)
{
    addItem(tr("绷带"));
    addItem(tr("褪色的丝带"));
    addItem(tr("男子汉头巾"));
    addItem(tr("旧芭蕾舞裙"));
    addItem(tr("多雾眼镜"));
    addItem(tr("彩绘围裙"));
    addItem(tr("牛仔帽"));
    addItem(tr("心形坠饰锁"));
    addItem(tr("坠饰锁"));
    addItem(tr("Temmie甲"));

	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void ArmorComboBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	adf->setValue(dfValues[i]);
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void ArmorComboBox::updateData()
{
	setCurrentIndex(indexes.value(mw->saveData.at(id).toInt()));
}

RoomComboBox::RoomComboBox(int id, MainWindow *mainWindow, QWidget *parent) : QComboBox(parent), id(id), mw(mainWindow)
{
    addItem(QString("废墟 - Entrance"));
    addItem(QString("废墟 - Leaf Pile"));
    addItem(QString("废墟 - Mouse Hole"));
    addItem(QString("废墟 - Home"));
    addItem(QString("雪町 - Box Road"));
    addItem(QString("雪町 - Spaghetti"));
    addItem(QString("雪町 - Dog House"));
    addItem(QString("雪町 - Town"));
    addItem(QString("瀑布 - Checkpoint"));
    addItem(QString("瀑布 - Hallway"));
    addItem(QString("瀑布 - Crystal"));
    addItem(QString("瀑布 - Bridge"));
    addItem(QString("瀑布 - Trash Zone"));
    addItem(QString("瀑布 - Quiet Area"));
    addItem(QString("瀑布 - Temmie Village"));
    addItem(QString("瀑布 - Undyne Arena"));
    addItem(QString("热地 - Laboratory Entrance"));
    addItem(QString("热地 - Magma Chamber"));
    addItem(QString("热地 - Core View"));
    addItem(QString("热地 - Bad Opinion Zone"));
    addItem(QString("热地 - Spider Entrance"));
    addItem(QString("热地 - Hotel Lobby"));
    addItem(QString("热地 - Core Branch"));
    addItem(QString("热地 - Core End"));
    addItem(QString("城堡电梯"));
    addItem(QString("新家"));
    addItem(QString("最终长廊"));
    addItem(QString("王座入口"));
    addItem(QString("王座房间"));
    addItem(QString("终点"));
    addItem(QString("真实验室"));
    addItem(QString("真实验室 - Bedroom"));
	addItem(QString("room_start"));
	addItem(QString("room_introstory"));
	addItem(QString("room_introimage"));
	addItem(QString("room_intromenu"));
	addItem(QString("room_area1"));
	addItem(QString("room_area1_2"));
    addItem(QString("废墟 - 2"));
    addItem(QString("废墟 - 3"));
    addItem(QString("废墟 - 4"));
    addItem(QString("废墟 - 5"));
    addItem(QString("废墟 - 6"));
    addItem(QString("废墟 - 7A"));
    addItem(QString("废墟 - 8"));
    addItem(QString("废墟 - 9"));
    addItem(QString("废墟 - 10"));
    addItem(QString("废墟 - 11"));
    addItem(QString("废墟 - 12"));
    addItem(QString("废墟 - 12B"));
    addItem(QString("废墟 - 13"));
    addItem(QString("废墟 - 14"));
    addItem(QString("废墟 - 15A"));
    addItem(QString("废墟 - 15B"));
    addItem(QString("废墟 - 15C"));
    addItem(QString("废墟 - 15D"));
    addItem(QString("废墟 - 15E"));
    addItem(QString("废墟 - 16"));
    addItem(QString("废墟 - 17"));
    addItem(QString("废墟 - 18OLD"));
    addItem(QString("家 - Entrance Hall"));
    addItem(QString("家 - Living Room"));
    addItem(QString("家 - Hall"));
    addItem(QString("家 - Toriel's Room"));
    addItem(QString("家 - Asriel's Room"));
    addItem(QString("家 - Kitchen"));
	addItem(QString("room_basement1"));
	addItem(QString("room_basement2"));
	addItem(QString("room_basement3"));
	addItem(QString("room_basement4"));
	addItem(QString("room_basement5"));
    addItem(QString("雪町 - Ruins Exit"));
    addItem(QString("雪町 - 1"));
    addItem(QString("雪町 - 2"));
    addItem(QString("雪町 - 3A"));
    addItem(QString("雪町 - 4"));
    addItem(QString("雪町 - 5"));
    addItem(QString("雪町 - 6"));
    addItem(QString("雪町 - 6A"));
    addItem(QString("雪町 - 7"));
    addItem(QString("雪町 - 8"));
    addItem(QString("雪町 - 8A"));
    addItem(QString("雪町 - 9"));
    addItem(QString("雪町 - Snow Puzzle"));
    addItem(QString("雪町 - XO Puzzle (Small)"));
    addItem(QString("雪町 - XO Puzzle (Papyrus)"));
    addItem(QString("雪町 - Tile Puzzle"));
    addItem(QString("雪町 - icehole"));
    addItem(QString("雪町 - iceentrance"));
    addItem(QString("雪町 - iceexit_new"));
    addItem(QString("雪町 - iceexit"));
    addItem(QString("雪町 - Snow Poff Zone"));
    addItem(QString("雪町 - Dangerous Bridge Puzzle"));
    addItem(QString("雪町 - town2"));
    addItem(QString("雪町 - Dock"));
    addItem(QString("雪町 - Snowed Inn"));
    addItem(QString("雪町 - Snowed Inn (2nd floor)"));
    addItem(QString("雪町 - Grillby's"));
    addItem(QString("雪町 - Library"));
    addItem(QString("雪町 - Garage"));
    addItem(QString("雪町 - Papyrus's and Sans's House"));
    addItem(QString("雪町 - Papyrus's Room"));
    addItem(QString("雪町 - Sans's Room"));
    addItem(QString("雪町 - Sans's Room (Dark)"));
    addItem(QString("雪町 - Sans's Basement"));
    addItem(QString("雪町 - Foggy Hallway"));
    addItem(QString("瀑布 - 1"));
    addItem(QString("瀑布 - 3"));
    addItem(QString("瀑布 - 3A"));
    addItem(QString("瀑布 - bridgepuzz1"));
    addItem(QString("瀑布 - 5"));
    addItem(QString("瀑布 - 5A"));
    addItem(QString("瀑布 - 6"));
    addItem(QString("瀑布 - 7"));
    addItem(QString("瀑布 - 8"));
    addItem(QString("瀑布 - 9"));
    addItem(QString("瀑布 - 11"));
    addItem(QString("瀑布 - nicecream"));
    addItem(QString("瀑布 - 12"));
    addItem(QString("瀑布 - shoe"));
    addItem(QString("瀑布 - bird"));
    addItem(QString("瀑布 - Onionsan"));
    addItem(QString("瀑布 - 14"));
    addItem(QString("瀑布 - Piano Puzzle"));
    addItem(QString("瀑布 - dogroom"));
    addItem(QString("瀑布 - Music Box Statue"));
    addItem(QString("瀑布 - prewaterfall"));
    addItem(QString("瀑布 - waterfall"));
    addItem(QString("瀑布 - waterfall2"));
    addItem(QString("瀑布 - waterfall3"));
    addItem(QString("瀑布 - waterfall4"));
    addItem(QString("瀑布 - undynebridge"));
    addItem(QString("瀑布 - undynebridgeend"));
    addItem(QString("瀑布 - trashzone1"));
    addItem(QString("瀑布 - trashzone2"));
    addItem(QString("瀑布 - Undyne's Yard"));
    addItem(QString("瀑布 - Undyne's House"));
    addItem(QString("瀑布 - Blooky's Yard"));
    addItem(QString("瀑布 - Blooky's House"));
    addItem(QString("瀑布 - hapstablook"));
    addItem(QString("瀑布 - Blook Farm"));
    addItem(QString("瀑布 - prebird"));
    addItem(QString("瀑布 - Gerson's Shop"));
    addItem(QString("瀑布 - Dock"));
    addItem(QString("瀑布 - 15"));
    addItem(QString("瀑布 - 16"));
    addItem(QString("瀑布 - 17"));
    addItem(QString("瀑布 - 18"));
    addItem(QString("瀑布 - 19"));
    addItem(QString("瀑布 - 20"));
    addItem(QString("瀑布 - Puzzle Elder"));
    addItem(QString("瀑布 - Arena Exit"));
    addItem(QString("瀑布 - Hotland Entrance"));
    addItem(QString("热地 - Sans's Station"));
    addItem(QString("热地 - Water Cooler"));
    addItem(QString("热地 - Dock"));
    addItem(QString("热地 - lab1"));
    addItem(QString("热地 - lab2"));
    addItem(QString("热地 - 3"));
    addItem(QString("热地 - 5"));
    addItem(QString("热地 - 6A"));
    addItem(QString("热地 - lasers1"));
    addItem(QString("热地 - 7"));
    addItem(QString("热地 - 8"));
    addItem(QString("热地 - shootguy_2"));
    addItem(QString("热地 - 9"));
    addItem(QString("热地 - shootguy_1"));
    addItem(QString("热地 - turn"));
    addItem(QString("热地 - cookingshow"));
    addItem(QString("热地 - elevator_r1"));
    addItem(QString("热地 - elevator_r2"));
    addItem(QString("热地 - hotdog"));
    addItem(QString("热地 - walkandbranch"));
    addItem(QString("热地 - sorry"));
    addItem(QString("热地 - apron"));
    addItem(QString("热地 - 10"));
    addItem(QString("热地 - rpuzzle"));
    addItem(QString("热地 - boysnightout"));
    addItem(QString("热地 - newsreport"));
    addItem(QString("热地 - coreview2"));
    addItem(QString("热地 - elevator_l2"));
    addItem(QString("热地 - elevator_l3"));
    addItem(QString("热地 - spidershop"));
    addItem(QString("热地 - walkandbranch2"));
    addItem(QString("热地 - conveyorlaser"));
    addItem(QString("热地 - shootguy_3"));
    addItem(QString("热地 - preshootguy4"));
    addItem(QString("热地 - shootguy_4"));
    addItem(QString("热地 - Spider's Web"));
    addItem(QString("热地 - pacing"));
    addItem(QString("热地 - operatest"));
    addItem(QString("热地 - Tile Puzzle EX"));
    addItem(QString("热地 - hotelfront_1"));
    addItem(QString("热地 - hotelfront_2"));
    addItem(QString("酒店 - Restaurant"));
    addItem(QString("热地 - hoteldoors"));
    addItem(QString("热地 - hotelbed"));
    addItem(QString("热地 - elevator_r3"));
    addItem(QString("热地 - precore"));
    addItem(QString("热地 - core1"));
    addItem(QString("热地 - core2"));
    addItem(QString("热地 - core3"));
    addItem(QString("热地 - core4"));
    addItem(QString("热地 - core5"));
    addItem(QString("热地 - core_freebattle"));
    addItem(QString("热地 - core_laserfun"));
    addItem(QString("热地 - core_bottomleft"));
    addItem(QString("热地 - core_left"));
    addItem(QString("热地 - core_topleft"));
    addItem(QString("热地 - core_top"));
    addItem(QString("热地 - core_topright"));
    addItem(QString("热地 - core_right"));
    addItem(QString("热地 - core_bottomright"));
    addItem(QString("热地 - core_center"));
    addItem(QString("热地 - shootguy_5"));
    addItem(QString("热地 - core_treasureleft"));
    addItem(QString("热地 - core_treasureright"));
    addItem(QString("热地 - core_warrior"));
    addItem(QString("热地 - core_bridge"));
    addItem(QString("热地 - core_metttest"));
    addItem(QString("热地 - core_final"));
    addItem(QString("热地 - elevator"));
    addItem(QString("热地 - elevator_l1"));
    addItem(QString("热地 - finalelevator"));
	addItem(QString("room_castle_precastle"));
	addItem(QString("room_castle_hook"));
	addItem(QString("room_asghouse1"));
	addItem(QString("room_asghouse2"));
	addItem(QString("room_asghouse3"));
	addItem(QString("room_asgoreroom"));
	addItem(QString("room_asrielroom_final"));
	addItem(QString("room_kitchen_final"));
	addItem(QString("room_basement1_final"));
	addItem(QString("room_basement2_final"));
	addItem(QString("room_basement3_final"));
	addItem(QString("room_basement4_final"));
	addItem(QString("room_lastruins_corridor"));
	addItem(QString("room_castle_coffins1"));
	addItem(QString("room_castle_coffins2"));
	addItem(QString("room_castle_barrier"));
	addItem(QString("room_castle_exit"));
	addItem(QString("room_undertale_end"));
	addItem(QString("room_castle_trueexit"));
	addItem(QString("room_outsideworld"));
    addItem(QString("热地 - labelevator"));
    addItem(QString("真实验室 - elevatorinside"));
    addItem(QString("真实验室 - elevator"));
    addItem(QString("真实验室 - hall1"));
    addItem(QString("真实验室 - hall2"));
    addItem(QString("真实验室 - operatingroom"));
    addItem(QString("真实验室 - Red Lever"));
    addItem(QString("真实验室 - prebed"));
    addItem(QString("真实验室 - mirror"));
    addItem(QString("真实验室 - Blue Lever"));
    addItem(QString("真实验室 - hall3"));
    addItem(QString("真实验室 - shower"));
    addItem(QString("真实验室 - determination"));
    addItem(QString("真实验室 - tv"));
    addItem(QString("真实验室 - cooler"));
    addItem(QString("真实验室 - Green Lever"));
    addItem(QString("真实验室 - fan"));
    addItem(QString("真实验室 - castle_elevator"));
    addItem(QString("真实验室 - prepower"));
    addItem(QString("真实验室 - power"));
	addItem(QString("room_gaster"));
	addItem(QString("room_icecave1"));
	addItem(QString("room_ice_dog"));
	addItem(QString("room2"));
    addItem(QString("瀑布 - fakehallway"));
	addItem(QString("room_mysteryman"));
	addItem(QString("room_soundtest"));
	addItem(QString("TESTROOM"));
    addItem(QString("瀑布 - redacted"));
    addItem(QString("瀑布 - 13"));
	addItem(QString("room_overworld"));
	addItem(QString("room_overworld3"));
	addItem(QString("bullettest"));
    addItem(QString("瀑布 - 16A"));
	addItem(QString("room_end_castroll"));
	addItem(QString("room_end_highway"));
	addItem(QString("room_end_beach"));
	addItem(QString("room_end_metta"));
	addItem(QString("room_end_school"));
	addItem(QString("room_end_mtebott"));
	addItem(QString("room_creditsdodger"));
	addItem(QString("room_end_myroom"));
	addItem(QString("room_end_theend"));
	addItem(QString("room_spritecheck"));
	addItem(QString("room_joyconfig"));
	addItem(QString("room_controltest"));
	addItem(QString("room_f_start"));
	addItem(QString("room_f_intro"));
	addItem(QString("room_f_menu"));
	addItem(QString("room_f_room"));
	addItem(QString("room_floweyx"));
	addItem(QString("room_f_phrase"));
    addItem(QString("热地 - 4"));
    addItem(QString("热地 - 10_old"));
    addItem(QString("热地 - 10A_old"));
    addItem(QString("雪町 - placeholder"));
    addItem(QString("废墟 - 12B_old"));
    addItem(QString("雪町 - rollsnow"));
    addItem(QString("瀑布 - 7_older"));
	addItem(QString("room_meetundyne_old"));
    addItem(QString("瀑布 - mushroom"));
	addItem(QString("room_monsteralign_test"));
	addItem(QString("room_battle"));
	addItem(QString("room_floweybattle"));
	addItem(QString("room_fastbattle"));
	addItem(QString("room_storybattle"));
	addItem(QString("room_gameover"));
	addItem(QString("room_shop1"));
	addItem(QString("room_shop2"));
	addItem(QString("room_shop3"));
	addItem(QString("room_shop4"));
	addItem(QString("room_shop5"));
	addItem(QString("room_riverman_transition"));
	addItem(QString("room_papdate"));
	addItem(QString("room_adate"));
	addItem(QString("room_flowey_endchoice"));
	addItem(QString("room_flowey_regret"));
	addItem(QString("room_empty"));
	addItem(QString("room_emptywhite"));
	addItem(QString("room_emptyblack"));
	addItem(QString("room_nothingness"));
	addItem(QString("room_undertale"));
	addItem(QString("room_of_dog"));
	addItem(QString("room_quizholder"));
	addItem(QString("room_friendtest"));
	addItem(QString("room_bringitinguys"));
	addItem(QString("room_asrielappears"));
	addItem(QString("room_goodbyeasriel"));
	addItem(QString("room_asrielmemory"));
	addItem(QString("room_asrieltest"));
	addItem(QString("room_afinaltest"));

	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void RoomComboBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void RoomComboBox::updateData()
{
	setCurrentIndex(indexes.value(mw->saveData.at(id).toInt()));
}

TimeEdit::TimeEdit(int id, MainWindow *mainWindow, QWidget *parent) : QWidget(parent), id(id), mw(mainWindow)
{
	data = new QDoubleSpinBox();
	data->setDecimals(0);
	data->setRange(0, INT64_MAX);
	label = new QLabel(QString("00:00:00"));

	setLayout(new QHBoxLayout());
	layout()->addWidget(label);
	layout()->addWidget(data);

	connect(data, SIGNAL(valueChanged(double)), this, SLOT(updateSave(double)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void TimeEdit::updateSave(double d)
{
	int h = qRound(d/108000.0);
	int m = qRound(d/1800) % 60;
	int s = qRound(d/30) % 60;
	label->setText(QString("%1:%2:%3").arg(h, 2, 'f', 0, '0').arg(m, 2, 'f', 0, '0').arg(s, 2, 'f', 0, '0'));
	mw->saveData.replace(id, QString::number(d, 'g', 5));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void TimeEdit::updateData()
{
	double d = mw->saveData.at(id).toDouble();
	data->setValue(d);
	int h = qRound(d/108000.0);
	int m = qRound(d/1800) % 60;
	int s = qRound(d/30) % 60;
	label->setText(QString("%1:%2:%3").arg(h, 2, 'f', 0, '0').arg(m, 2, 'f', 0, '0').arg(s, 2, 'f', 0, '0'));
}


PlotEdit::PlotEdit(int id, MainWindow *mainWindow, QWidget *parent) : QComboBox(parent), id(id), mw(mainWindow)
{
    addItem(tr("新游戏"));
    addItem(tr("见过Flowey"));
    addItem(tr("Toriel领着你进入下一个房间"));
    addItem(tr("Toriel讲解了谜题"));
    addItem(tr("开关谜题开始"));
    addItem(tr("拉下第一个开关"));
    addItem(tr("拉下第二个开关"));
    addItem(tr("练习用人偶"));
    addItem(tr("与人偶互动"));
    addItem(tr("与人偶互动结束"));
    addItem(tr("危险谜题开始"));
    addItem(tr("危险谜题结束"));
    addItem(tr("独立测试开始"));
    addItem(tr("独立测试结束"));
    addItem(tr("Toriel打电话叫你不要离开房间"));
    addItem(tr("Toriel打电话问派的口味"));
    addItem(tr("Toriel再次打电话"));
    addItem(tr("Toriel打电话问过敏"));
    addItem(tr("鼓励了Napstablook"));
    addItem(tr("Napstablook遭遇战结束"));
    addItem(tr("与Napstablook对话"));
    addItem(tr("Napstablook消失"));
    addItem(tr("Toriel打电话提醒拿物品"));
    addItem(tr("按下掉落地板谜题的开关"));
    addItem(tr("按下蓝色开关"));
    addItem(tr("按下红色开关"));
    addItem(tr("按下绿色开关"));
    addItem(tr("再次遇到Toriel"));
    addItem(tr("Toriel提到派"));
    addItem(tr("Toriel给你看了你的房间"));
    addItem(tr("与Toriel对话"));
    addItem(tr("与Toriel更多的对话"));
    addItem(tr("与Toriel还更多的对话"));
    addItem(tr("听过了蜗牛的用处"));
    addItem(tr("你问过\"如何离开废墟\""));
    addItem(tr("Toriel去做了什么"));
    addItem(tr("Toriel进入地下室"));
    addItem(tr("Toriel准备摧毁出口"));
    addItem(tr("Toriel向你警告了Asgore"));
    addItem(tr("Toriel最后一次警告你"));
    addItem(tr("Toriel战斗结束"));
    addItem(tr("与Flowey对话过"));
    addItem(tr("走出废墟"));
    addItem(tr("形状便利的灯"));
    addItem(tr("sans离开画面"));
    addItem(tr("Papyrus遇到人类"));
    addItem(tr("Doggo遭遇战结束"));
    addItem(tr("Doggo去吃狗零食"));
    addItem(tr("解开了电击迷宫"));
    addItem(tr("\"解开\"了sans的谜题"));
    addItem(tr("找到被埋起来的开关"));
    addItem(tr("Dogamy和Dogaressa遭遇战结束"));
    addItem(tr("Dogamy和Dogaressa离开"));
    addItem(tr("解开第一个XO谜题"));
    addItem(tr("到达第二个XO谜题"));
    addItem(tr("解开第二个XO谜题"));
    addItem(tr("跳过了XO谜题"));
    addItem(tr("\"解开\"了彩砖谜题"));
    addItem(tr("Greater Dog遭遇战结束"));
    addItem(tr("Greater Dog遭遇战结束"));
    addItem(tr("解开了第三个XO谜题"));
    addItem(tr("Greater Dog离开"));
    addItem(tr("\"解开\" the final谜题"));
    addItem(tr("Papyrus遭遇战结束"));
    addItem(tr("Papyrus离开"));
    addItem(tr("(未使用) Monster Kid事件触发"));
    addItem(tr("Undyne在海草里看见你"));
    addItem(tr("Papyrus打电话问你的护甲"));
    addItem(tr("找到隐藏门"));
    addItem(tr("(未使用) 解开火把谜题"));
    addItem(tr("Undyne在海草里抓到Monster Kid"));
    addItem(tr("遇到Shyren"));
    addItem(tr("Monster Kid准备帮你爬上岩壁"));
    addItem(tr("Monster Kid离开"));
    addItem(tr("在垃圾场醒来"));
    addItem(tr("Mad Dummy遭遇战结束"));
    addItem(tr("Napstablook回家"));
    addItem(tr("Undyne带走了Monster Kid"));
    addItem(tr("走到了回音花小路尽头"));
    addItem(tr("Monster Kid在桥上绊倒"));
    addItem(tr("Undyne准备与你开战"));
    addItem(tr("Undyne遭遇战结束"));
    addItem(tr("Mettaton的真人秀"));
    addItem(tr("Alphys升级了你的电话"));
    addItem(tr("Alphys挂掉电话"));
    addItem(tr("Alphys打电话说明激光"));
    addItem(tr("Alphys打电话说明设计谜题"));
    addItem(tr("第一扇大门打开"));
    addItem(tr("Alphys再次打电话说明谜题"));
    addItem(tr("Alphys在Mettaton的烹饪秀打进电话"));
    addItem(tr("Mettaton的烹饪秀结束"));
    addItem(tr("Alphys打电话讲解核心"));
    addItem(tr("Alphys打电话讲解传送带谜题"));
    addItem(tr("Alphys试着修改定时"));
    addItem(tr("Alphys打电话说要去洗手间"));
    addItem(tr("Royal Guard遭遇战结束"));
    addItem(tr("跳过Hotland谜题"));
    addItem(tr("MTT新闻结束"));
    addItem(tr("Alphys打电话提到Asgore"));
    addItem(tr("Alphys打电话讲解射击谜题"));
    addItem(tr("打开第二扇大门"));
    addItem(tr("Muffet遭遇战结束"));
    addItem(tr("Mettaton歌剧"));
    addItem(tr("Mettaton的彩砖谜题完成"));
    addItem(tr("离开MTT酒店"));
    addItem(tr("Alphys在核心大厅打进电话"));
    addItem(tr("与雇佣兵战斗过"));
    addItem(tr("Alphys打电话说明激光顺序（错误）"));
    addItem(tr("Alphys打电话道歉"));
    addItem(tr("Alphys打电话建议走右边"));
    addItem(tr("(未使用)激光事件"));
    addItem(tr("Alphys打电话说一切还可控"));
    addItem(tr("Alphys在核心岔路口打电话"));
    addItem(tr("Mettaton EX遭遇战结束"));
    addItem(tr("Alphys说明真相"));
    addItem(tr("sans对你的审判"));
    addItem(tr("遇见Asgore"));
    addItem(tr("Asgore提到现在有多紧张"));
    addItem(tr("Asgore进入了屏障所在房间"));
    addItem(tr("真和平结局"));

	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}
void PlotEdit::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	emit dataChanged(true);
	emit mw->updateWidgets();
}
void PlotEdit::updateData()
{
	setCurrentIndex(indexes.value(mw->saveData.at(id).toInt()));
}

YellowNameCheckBox::YellowNameCheckBox(int id, MainWindow *mainWindow, QWidget *parent) : QCheckBox(parent), id(id), mw(mainWindow)
{
	connect(this, SIGNAL(stateChanged(int)), this, SLOT(updateSave(int)));
	connect(mw, SIGNAL(updateWidgets()), this, SLOT(updateData()));
	connect(this, SIGNAL(dataChanged(bool)), mw, SLOT(fileModified(bool)));
}

void YellowNameCheckBox::updateSave(int i)
{
	mw->saveData.replace(id, QString::number(values[i]));
	emit dataChanged(true);
	emit mw->updateWidgets();
}

void YellowNameCheckBox::updateData()
{
	setCheckState(states.value(mw->saveData.at(id).toInt()));
}
