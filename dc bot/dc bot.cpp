#include <iostream> 
#include <string>
#include <vector>
#include <dpp/dpp.h>
#include <random>
#include <fstream>

using namespace std;
using json = nlohmann::json;

string nero[18] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1092538926687858828/1680551962912.jpg",
    "https://media.discordapp.net/attachments/968693698206519356/1092538926914359466/1680551964443.jpg?width=1050&height=735",
    "https://cdn.discordapp.com/attachments/968693698206519356/1092709412789030972/16051910383634.png",
    "https://cdn.discordapp.com/attachments/933710044917288963/1092728926054400030/70027330_p0_master1200.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1093091882638254110/90495379_p0.png",  // 5
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092021884956702/106295232_p0_master1200.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092114721689620/100877791_p0_master1200.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092323023392818/106192093_p0.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092538400903188/106416803_p0_master1200.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092623398477824/100508530_p0.png" ,  // 10
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092717183119381/98878276_p0_master1200.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092779489505360/71238969_p0_master1200.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092836917919814/90495379_p0_master1200.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093092898981036053/89517369_p0_master1200.png" ,
    "https://cdn.discordapp.com/attachments/968693698206519356/1093095677170565150/67090381_p0_master1200.png" ,  // 15
    "https://cdn.discordapp.com/attachments/968693698206519356/1093095720455782441/91937298_p0_master1200.png",
    "媽的怎麼有個智障又在刷圖了",
    "媽的怎麼有個智障又在刷圖了"
};
string exusiai[32] = {
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364786424721458/74871383_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364800966369371/79067802_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364833891663892/79640496_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364858835173466/101872504_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364890313437184/105525478_p0.png",  // 5
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364936853422231/103486827_p0.png",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364960098275459/105829323_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364993694638110/101933810_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365024522772491/104753423_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365055019548744/99347539_p0_1.jpg",  // 10
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365087139536916/83439562_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365103606374502/93266233_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365117548236910/91879173_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365135009132585/103866984_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365150003757056/101028272_p0.jpg",  // 15
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365164444745768/102634213_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365189212119152/79405727_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365203921543270/105116769_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365220786851901/101872743_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365235647258734/104348996_p0.jpg",  // 20
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365266253086770/91809487_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365280455000164/97693106_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1097845294772789298/87451043_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365918169575494/105844530_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1097845025695604797/75387374_p1.jpg",  // 25
    "https://cdn.discordapp.com/attachments/970373508209201262/1097845286216413294/82169692_p0.png",
    "https://cdn.discordapp.com/attachments/970373508209201262/1097845033400545320/106220663_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1107562685312290847/101931248_p0.png",
    "https://cdn.discordapp.com/attachments/970373508209201262/1107562558308753488/93447113_p0.png",
    "https://cdn.discordapp.com/attachments/970373508209201262/1107562536116691034/107951126_p0.jpg",  // 30
    "媽的怎麼有個智障又在刷圖了",
    "媽的怎麼有個智障又在刷圖了"
};
string dalao[11] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600372762808330/65bbfd846d3437b0dd9ed947dcc4816f.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600521085976576/1586869262198.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600614879010827/1619758952948.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600682138882138/1578841721163.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600776976269343/1636001561524.png",  // 5
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600885793300480/1574742490553.png",
    "https://cdn.discordapp.com/attachments/966719485438476318/1103622392288399390/IMG_6535.GIF",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599188410880030/FB_IMG_1667864424847.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599543236399144/FB_IMG_1664012145347.jpg",
    "https://cdn.discordapp.com/attachments/988843667479470130/1109721623147331604/kitten-cat.gif",
    "https://media.discordapp.net/attachments/727443536085254186/883883935141101589/image0.gif?width=87&height=87"
};
string europe[5] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601634916966471/64819726415fa4d795ccc6269f6e560b.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601681616347206/1604671763242.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601790546620416/Z.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601842497273947/2Q.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105809939575865344/gif21.gif"  // 5
};
string fbi[10] = {
    "https://media.discordapp.net/attachments/968693698206519356/1108597185219678229/IMG_7547.jpg?width=525&height=290",
    "https://media.discordapp.net/attachments/968693698206519356/1108597185471328376/IMG_7554.jpg?width=556&height=535",
    "https://media.discordapp.net/attachments/968693698206519356/1108597186595409930/IMG_7545.jpg?width=486&height=316",
    "https://media.discordapp.net/attachments/968693698206519356/1108597186855448586/F6724091-B209-4DAE-AEC4-C8329355F37C.jpg?width=875&height=784",  //改到這裡
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599151341608970/FB_IMG_1660108263198.jpg",  // 5
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599158497103913/FB_IMG_1660108235341.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599745422819388/FB_IMG_1663562166764.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599921914957924/FB_IMG_1671091950520.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108600042484416522/FB_IMG_1660108222520.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108600051959353394/FB_IMG_1678977575738.jpg"  // 10
};
string kusa[7] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1105809138061152276/1683715825278.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105809322727981167/8033ffd8b66053cc9ab07c53d7652654.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105821584322727936/th.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105821215249137834/20210920000704.png",
    //"h ttps://cdn.discordapp.com/attachments/968693698206519356/1105821914963902525/4Bgi4BnYfKrlUBUnXRJT5E.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105821317627916329/ddb0503a3043e33f88225cf9b7b42a93.png",  // 5
    "https://cdn.discordapp.com/attachments/968693698206519356/1105822361757941830/ddhBcLX.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105822741296332940/HeP1P5a.png"
};
string truee[5] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1092781449641463859/1648880999715.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1092781578129772664/1652857835934.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1092781749743931432/1672283745170-ba37455ba44240a293fb5cb3531811f9-500x333.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105809663716503613/51.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105823436883902484/Mvd47Q7.png"  // 5
};
string gaygay[23] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832383690854420/image.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832408504344647/image.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832434081214484/image.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832565614579712/FB_IMG_1682333588762.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832573214662726/FB_IMG_1682333706439.jpg",  // 5
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832631880384562/FB_IMG_1682333716746.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832654428966913/FB_IMG_1683261099671.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832662465269890/FB_IMG_1683261103147.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832670308601876/FB_IMG_1683261108602.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832678147764264/FB_IMG_1683261111120.jpg",  // 10
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832706958442526/FB_IMG_1683261114859.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832714109734932/FB_IMG_1683261118551.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832721873383425/FB_IMG_1683261123186.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832728647188531/FB_IMG_1683261127906.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832945031319632/3XPdxWs.png",  // 15
    "https://cdn.discordapp.com/attachments/968693698206519356/1105832993718796348/AFNrAvE.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105833014640001034/9RzeBsC.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105833036261625917/okcPVSB.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105833073901305906/mDq8Du2.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105833092284960869/rsLmsEx.png",  // 20
    "https://cdn.discordapp.com/attachments/968693698206519356/1105834957118644224/584E45F3-4090-4C2F-ABF7-D38D4B2E7DA2.jpg",
    "https://cdn.discordapp.com/attachments/981585424017420378/1105834260557996102/ZomboMeme_02052023151522.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1110106858477326376/348551627_234395815863993_2485886371128395134_n.png"
};
string wat[16]{"https://cdn.discordapp.com/attachments/966727921467260938/1107671890601988196/FB_IMG_1666237078979.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107671945065025657/FB_IMG_1683964567949.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107671953411686503/FB_IMG_1641285775513.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672007996346368/IMG_20211218_120954_767.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672021992734740/received_336306151969779.jpg",  // 5
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672068935397477/FB_IMG_1649072900407.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672137059278959/1647449461391.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672194118586418/FB_IMG_1646054813327.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672218546225173/FB_IMG_1645529431013.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672270853386301/FB_IMG_1681610899807.jpg",  // 10
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672270853386301/FB_IMG_1681610899807.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672277270667324/FB_IMG_1659047938208.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672286321967217/Screenshot_20230126-213009.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672305133428836/Screenshot_20230209-080633.jpg",
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672350268334171/Screenshot_20230501_103044.jpg",  //15
    "https://cdn.discordapp.com/attachments/966727921467260938/1107672365162307704/FB_IMG_1670764145912.jpg"
};
string mat[51]{
    "1-3 海盜船 (同時缺虛影之塵就去 1-5 夏洛特)",
    "冬木 X-G (X-C也行，單件期望AP較低但要打較多場，X-D也是同理)",
    "1-5 德明 (1-7 埃里都也行，關卡消耗AP較高導致雖然掉率較高但單件期望理智也較高)",
    "1-5 夏洛特",
    "1-6 死之荒野",  // 5
    "1-7 蘆葦原",
    "1.5-1 新宿站",
    "1.5-4 絞刑丘陵",
    "2-1 雅嘎·斯摩稜斯克",
    "2-6 霧之海岸",  // 10
    "2-6.5 シルミウム",
    "2-6.5 ヨウィヌス砦(若同時缺儀式劍則可以刷 2-6.5 クサンテンの塔)",
    "1-7 廢都巴比倫",
    "1-7 庫撒",
    "1-5.2 桃源鄉",  // 15
    "1-5.2 大地裂隙",
    "1.5-4 公會堂",
    "1.5-1 槍身塔(同時缺弓職的秘、魔、輝石可以去 1-5 芝加哥)",
    "1.5-1 新宿二丁目",
    "1.5-4 維特利家",  // 20
    "1-6 無之大地",
    "1-6 王城",
    "1-7 觀測所",
    "1.5-3 城下町",
    "2-1 雅嘎·莫斯科",  // 25
    "2-2 巨人的花園",
    "2-2 雪與冰之城",
    "2-3 八門洞",
    "2-4 神之空岩遺跡(同時有缺金蛋可去 2-4 迪瓦爾)",
    "2-5.1 塔納托斯島(同時有缺煌星碎片可去 2-5.1 涅墨西斯島)",  // 30
    "2-5.2 地下機構帶·外圍(同時缺悠久果實可去 2-5.2 星間都市南部)",
    "2-5.5 五條大橋(同時缺鬼炎鬼灯可去 2-5.5 三條三坊)",
    "2-6 倫蒂尼恩(同時缺小鐘可去 2-6 牛津)",
    "2-5.2 滑翔點(同時缺蛇之寶玉)、2-5.1 赫卡忒島(同時缺光銀之冠)、2-4 西之斷層(同時缺禍罪箭頭)、2-1 雅嘎·梁贊(同時缺永遠結冰)、1.5-2 地底平原(同時缺龍牙)、1.5-1 新宿四丁目(同時缺魔術髓液)",
    "1.5-4 卡特家(同時缺鐵樁)、1.5-1 新宿御宛(同時缺魔術髓液)(因為掉率太低(掉率12%上下)，建議活動再收集)",  // 35
    "2-6 グロスター(同時缺小鐘和灰塵)1-7 尼普爾(同時缺萬死毒針)",
    "2-5.2 阿斯特蕾亞島(同時缺光銀之冠和灰塵)、2-2 被遺忘的神殿(同時缺極光之鋼)、1.5-1 塔頂樓(同時缺無間齒輪)、1-6 聖都市街(同時缺英雄之證和八連雙晶)(因為掉率太低(掉率10%上下)，建議活動再收集)",
    "2-4 起始點(同時缺箭頭)、2-1 雅嘎·傑緬斯克(同時缺永遠結冰)、2-1 反叛軍的堡壘(同時缺火藥)、2-1 錨點(同時缺毒針)、1.5-2 野營地(同時缺羽毛和世界樹之種)(因為掉率太低(掉率15%上下)，建議活動再收集)",
    "1.5-1 新宿二丁目(同時缺書頁)、1-5 亞歷山德里亞(同時缺英雄之證)(因為掉率太低(掉率15%上下)，建議活動再收集)",
    "2-4 隱遁窟(同時缺箭頭)、1.5-2 北部斷崖(同時缺鎖鏈)",  // 40
    "2-4 東之花園(同時缺羽毛)、1.5-4 拘留所(同時缺龍牙)",
    "1-6 大神殿(同時缺鎖鏈)、沙塵暴的沙漠(同時缺凶骨)(因為掉率太低(掉率10%上下)，建議活動再收集)",
    "2-2 通往盡頭之路(同時缺巨人指輪)、第67村落(同時缺極光鋼)、1-7 鮮血神殿(同時缺世界樹之種)",
    "1.5-3 荒川之原(同時缺勾玉和灰塵)、1-7 艾比夫山(同時缺世界樹之種)(因為掉率太低(掉率12%上下)，建議活動再收集)",
    "2-5.2 大工房(同時缺神脈靈子和灰塵)、2-5.1 赫斯提雅島(同時缺光銀之冠)、2-3 冰冷窟(同時缺世界樹之種)、2-1 大溪谷之堡壘(缺灰塵和火藥)、1.5-3 土氣城(同時缺勾玉和灰塵)、1.5-2 龍宮城(同時缺英雄之證)(因為掉率太低(掉率10%上下)，建議活動再收集)",  // 45
    "2-5.2 破神同盟基地(同時缺神脈靈子)、星間都市西部(同時缺悠久果實)、2-5.1 忒提斯島(同時缺蛇之寶玉)、2-3 石泉峽(同時缺無間齒輪)、收容所(同時缺閑古鈴)",
    "1.5 - 3 後山(戰戰競競)",
    "2-5.5 稲荷神社(同時缺無間齒輪)、2-4 迪瓦爾(同時缺箭頭)、北之靈峰(同時缺灰塵和鎖鏈)、無窮之地(同時缺羽毛和灰塵)",
    "2-5.2 機神迴廊(同時缺蛇之寶玉)、空中庭園(同時缺神脈靈子)、2-5.1 涅墨西斯島(同時缺光銀之冠)、啟航點(同時缺貝殼)",
    "2-5.2 星間都市南部(同時缺神脈靈子)、星間都市東部(同時缺八連雙晶)、星間都市西部(同時缺曉光爐心)、祭壇街(同時缺蛇之寶玉)",  // 50
    "2-5.5 三條三坊(同時缺虹色線球)、大江山(同時缺凶骨)、朱雀門(同時缺勾玉) "
};

string gacha = "";
string tokyotonumazu = "https://cdn.discordapp.com/attachments/1063968936464482324/1119267625869004840/image.png\nhttps://cdn.discordapp.com/attachments/1063968936464482324/1119267744622317628/image.png\nhttps://cdn.discordapp.com/attachments/1063968936464482324/1119267874641563648/image.png";
string numazutotokyo = "https://cdn.discordapp.com/attachments/1063968936464482324/1119270096225972286/image.png\nhttps://cdn.discordapp.com/attachments/1063968936464482324/1119272284448890940/image.png\nhttps://cdn.discordapp.com/attachments/1063968936464482324/1119273118150692975/image.png";
string jrtime = "https://www.eki-net.com/Personal/Top/Index\nhttps://www.jreast.co.jp/tickets/\nhttps://ekitan.com/timetable/railway/line/5000";

string pcrgacha(string times) {
    int integer = std::stoi(times);
    int pcrga[3] = {0};
    mt19937 mt(time(nullptr));

    for (int k = 0; k < integer; k++) {
        int r = mt() % 33;

        switch (r) {
        case 27:
            pcrga[0]++;
            break;

        case 15: case 9: case 31:
            pcrga[1]++;
            break;

        default:
            pcrga[2]++;
            break;
        }
    }

    string silver = to_string(pcrga[2]);
    string golden = to_string(pcrga[1]);
    string rainbow = to_string(pcrga[0]);
    gacha = "一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n" + golden + "張金卡<:pcr2:1117798436427804754>\n" + rainbow + "張彩卡<:pcr3:1117798715957194923>\n";
    return gacha;
}
string fgogacha(string times) {
    int integer = std::stoi(times);
    int fgoga[3] = {0};
    mt19937 mt(time(nullptr));

    for (int k = 0; k < integer; k++) {
        int r = mt() % 100;

        switch (r) {
        case 47:
            fgoga[0]++;
            break;

        case 85: case 98: case 6:
            fgoga[1]++;
            break;

        default:
            fgoga[2]++;
            break;
        }
    }
    string silver = to_string(fgoga[2]);
    string golden = to_string(fgoga[1]);
    string rainbow = to_string(fgoga[0]);
    gacha = "先說，我沒有保底\n\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n" + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n";
    return gacha;
}
string arkgacha(string times) {
    int integer = std::stoi(times);
    mt19937 mt(time(nullptr));
    int arkga[4] = { 0 };

    for (int i = 0; i < integer; i++) {
        int r = mt() % 50;

        switch (r) {
        case 27:  //六星
            arkga[0]++;
            break;

        case 35: case 43: case 15: case 1:  //五星
            arkga[1]++;
            break;

        case 5: case 29: case 45: case 18: case 20: case 3: case 26: case 48: case 32: case 40: case 39: case 16: case 8: case 21: case 4:  //四星
            arkga[2]++;
            break;

        default:  //三星
            arkga[3]++;
            break;
        }
    }
    string bronze = to_string(arkga[3]);
    string silver = to_string(arkga[2]);
    string golden = to_string(arkga[1]);
    string rainbow = to_string(arkga[0]);
    gacha = "先說，我沒有保底\n\n一共抽到了：\n" + bronze + "張三星<:ark3:1107953947353808947>\n" + silver + "張四星<:ark4:1107953907377901579>\n" + golden + "張五星<:ark5:1107953865602637824>\n" + rainbow + "張六星<:ark6:1107953803057188905>\n";
    return gacha;
}
string pcrget() {
    int pcrga[3] = { 0 };
    int k = 0;
    mt19937 mt(time(nullptr));

    while (pcrga[0] == 0 && k < 199) {
        int r = mt() % 33;

        switch (r) {
        case 27:
            pcrga[0]++;
            break;

        case 15: case 9: case 31:
            pcrga[1]++;
            break;

        default:
            pcrga[2]++;
            break;
        }
        k++;
    }
    string times = to_string(k);
    string silver = to_string(pcrga[2]);
    string golden = to_string(pcrga[1]);
    string rainbow = to_string(pcrga[0]);

    if (k < 199)
        gacha = "一共抽了" + times + "抽\n一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n" + golden + "張金卡<:pcr2:1117798436427804754>\n1張彩卡<:pcr3:1117798715957194923>\n";
    else
        gacha = "一共抽了200抽\n一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n" + golden + "張金卡<:pcr2:1117798436427804754>\n" + rainbow + "張彩卡<:pcr3:1117798715957194923>\n";
    
    return gacha;
}
string fgoget() {
    int fgoga[3] = {0};
    int k = 0;
    mt19937 mt(time(nullptr));

    while (fgoga[0] == 0 && k < 329) {
        int r = mt() % 100;
        switch (r) {
        case 47:
            fgoga[0]++;
            break;

        case 85: case 98: case 6:
            fgoga[1]++;
            break;

        default:
            fgoga[2]++;
            break;
        }
        k++;
    }
    string times = to_string(k);
    string silver = to_string(fgoga[2]);
    string golden = to_string(fgoga[1]);
    string rainbow = to_string(fgoga[0]);

    if (k < 329)
        gacha = "一共抽了" + times + "抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n" + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n";
    else
        gacha = "一共抽了330抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n" + golden + "張金卡<:fgo_K2:1107145363795746977>\n1張彩卡<:fgo_K1:1107145268681519114>\n";
    return gacha;
}

int main() {
    ifstream in;
    string token = "";
    in.open("token.txt");
    in >> token;
    dpp::cluster bot(token, dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    srand(time(NULL));

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {

        if (event.command.get_command_name() == "new_waifu") {
            event.reply("https://cdn.discordapp.com/attachments/966729542800658442/1092428172705931355/FB_IMG_1625811644856.jpg");

        }else if (event.command.get_command_name() == "cattie") {
            event.reply("https://cdn.discordapp.com/attachments/973282252186349588/1083963031077265528/IMG_6734.jpg");

        }else if (event.command.get_command_name() == "nero") {
            mt19937 mt(time(nullptr));
            event.reply(nero[mt() % size(nero)]);

        }else if (event.command.get_command_name() == "bruh") {
            event.reply("https://cdn.discordapp.com/attachments/933710044917288963/1092725740195295252/9k.png");

        }else if (event.command.get_command_name() == "exusiai") {
            mt19937 mt(time(nullptr));
            event.reply(exusiai[mt() % size(exusiai)]);

        }else if (event.command.get_command_name() == "mahjong") {
            event.reply("https://media.discordapp.net/attachments/988812288549093478/1099698505704022057/9F7E7973-93C7-4B07-9324-16D4BECC70A5.jpg");

        }
        }); //註冊斜線指令

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                dpp::slashcommand("ping", "Ping pong!", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("new_waifu", "doge", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("cattie", "cute", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("nero", "it'll send pics", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("bruh", "bro", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("true", "true", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("help", "function", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("exusiai", "it'll send pics", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("mahjong", "let's play", bot.me.id)
            );
        }
        }); //使用斜線指令
    
    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        string s = event.msg.content;
        vector<string> v;
        while(v.size() < 4){
            v.push_back(s.substr(0, s.find(" ")));
            s = s.substr(s.find(" ") + 1, s.length()); 

            if (s.find(" ") == 1) {
                v.push_back(s);            
                break;
            }
        }
        //拆訊息

        if (v[0] == "test") {
            fgogacha("32");
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "^n") {
            string carnum = "https://nhentai.net/g/" + v[1];
            dpp::message msg(event.msg.channel_id, carnum);
            bot.message_create(msg);
        }
        else if (v[0] == "^p") {
            string pixweb = "https://www.pixiv.net/artworks/" + v[1];
            dpp::message msg(event.msg.channel_id, pixweb);
            bot.message_create(msg);
        }
        else if (v[0] == "europe"
            || v[0] == "歐"
            || v[0] == "歐皇"
            || v[0] == "歐洲"
            || v[0] == "歐洲人") {
            mt19937 mt(time(nullptr));
            string eu = europe[mt() % size(europe)];  //https://github.com/Fate-Grand-Automata/FGA
            dpp::message msg(event.msg.channel_id, eu);
            bot.message_create(msg);
        }
        else if (v[0] == "fga") {
            dpp::message msg(event.msg.channel_id, "https://github.com/Fate-Grand-Automata/FGA");
            bot.message_create(msg);
        }
        else if (v[0] == "婆"
            || v[0] == "我婆"
            || v[0] == "這我婆"
            || v[0] == "又你婆") {
            dpp::message msg(event.msg.channel_id, "https://cdn.discordapp.com/attachments/966729542800658442/1092428172705931355/FB_IMG_1625811644856.jpg");
            bot.message_create(msg);
        }
        else if (v[0] == "true"
            || v[0] == "確實"
            || v[0] == "雀食") {
            mt19937 mt(time(nullptr));
            string tr = truee[mt() % size(truee)];
            dpp::message msg(event.msg.channel_id, tr);
            bot.message_create(msg);
        }
        else if (v[0] == "<:lao:1012343248095821914>"
            || v[0] == "<:lao:1089079085327732738>"
            || v[0] == "佬"
            || v[0] == "大佬"
            || v[0] == "老") {
            mt19937 mt(time(nullptr));
            string lao = dalao[mt() % size(dalao)];
            dpp::message msg(event.msg.channel_id, lao);
            bot.message_create(msg);
        }
        else if (v[0] == "<:kusa:1043444810259910748>"
            || v[0] == "<:kusa:1080709220451745853>"
            || v[0] == "草"
            || v[0] == "笑死"
            || v[0] == "笑"
            || v[0] == "kusa"
            || v[0] == "w"
            || v[0] == "ww"
            || v[0] == "www") {
            mt19937 mt(time(nullptr));
            string ku = kusa[mt() % size(kusa)];
            dpp::message msg(event.msg.channel_id, ku);
            bot.message_create(msg);
        }
        else if (v[0] == u8"🏳️‍🌈"
            || v[0] == u8"🏳️‍🌈❓"
            || v[0] == "gay"
            || v[0] == "甲"
            || v[0] == "給"
            || v[0] == "你是甲"
            || v[0] == "你是給"
            || v[0] == u8"🈸") {
            mt19937 mt(time(nullptr));
            string gay = gaygay[mt() % size(gaygay)];
            dpp::message msg(event.msg.channel_id, gay);
            bot.message_create(msg);
        }
        else if (v[0] == u8"🚔"
            || v[0] == u8"🚓"
            || v[0] == "fbi"
            || v[0] == "ㄌㄌㄎ"
            || v[0] == "ㄈㄅㄌ"
            || v[0] == "你是ㄌㄌㄎ") {
            mt19937 mt(time(nullptr));
            string fbifbi = fbi[mt() % size(fbi)];
            dpp::message msg(event.msg.channel_id, fbifbi);
            bot.message_create(msg);
        }
        else if (v[0] == "雀"
            || v[0] == "雀嗎"
            || v[0] == "@雀士"
            || v[0] == "有人要雀嗎"
            || v[0] == "現在有人要雀嗎"
            || v[0] == "誰要雀"
            || v[0] == "雀！") {
            dpp::message msg(event.msg.channel_id, "https://media.discordapp.net/attachments/988812288549093478/1099698505704022057/9F7E7973-93C7-4B07-9324-16D4BECC70A5.jpg");
            bot.message_create(msg);
        }
        else if (v[0] == "能"
            || v[0] == "能天"
            || v[0] == "阿能"
            || v[0] == "能天使") {
            mt19937 mt(time(nullptr));
            string exu = exusiai[mt() % size(exusiai)];
            dpp::message msg(event.msg.channel_id, exu);
            bot.message_create(msg);
        }
        else if (v[0] == "尼祿"
            || v[0] == "nero") {
            mt19937 mt(time(nullptr));
            string ner = nero[mt() % size(nero)];
            dpp::message msg(event.msg.channel_id, ner);
            bot.message_create(msg);
        }
        else if (v[0] == "瓜"
            || v[0] == "吃瓜") {
            dpp::message msg(event.msg.channel_id, "https://cdn.discordapp.com/attachments/503219154413682713/1107119476333350923/gcj_star230505.gif");
            bot.message_create(msg);
        }
        else if (v[0] == "bonk"
            || v[0] == "不可以瑟瑟"
            || v[0] == "不可以色色") {
            dpp::message msg(event.msg.channel_id, "<a:emoji_23:1008963509431840838>");
            bot.message_create(msg);
        }
        else if (v[0] == "JR去程"
            || v[0] == "jr去程"
            || v[0] == "去程"
            || v[0] == "沼津去程") {
            dpp::message msg(event.msg.channel_id, tokyotonumazu);
            bot.message_create(msg);
        }
        else if (v[0] == "JR回程"
            || v[0] == "jr回程"
            || v[0] == "回程"
            || v[0] == "沼津回程") {
            dpp::message msg(event.msg.channel_id, numazutotokyo);
            bot.message_create(msg);
        }
        else if (v[0] == "JR時刻"
            || v[0] == "jr時刻"
            || v[0] == "JR時刻查詢"
            || v[0] == "jr時刻查詢") {
            dpp::message msg(event.msg.channel_id, jrtime);
            bot.message_create(msg);
        }
        else if (v[0] == "<:Setsuna:1074672084132827237>"
            || v[0] == "<:Setsuna:1074672084132827237> <:Setsuna:1074672084132827237>"
            || v[0] == "<:Setsuna:1074672084132827237> <:Setsuna:1074672084132827237> <:Setsuna:1074672084132827237>"
            || v[0] == "<:Kyaru_confused:966726451636355112> "
            || v[0] == "<:Kyaru_confused:966726451636355112> <:Kyaru_confused:966726451636355112>"
            || v[0] == "<:Kyaru_confused:966726451636355112> <:Kyaru_confused:966726451636355112> <:Kyaru_confused:966726451636355112>"
            || v[0] == "<:pte_lemon:986265384992772166>"
            || v[0] == "<:pte_lemon:986265384992772166> <:pte_lemon:986265384992772166>"
            || v[0] == "<:pte_lemon:986265384992772166> <:pte_lemon:986265384992772166> <:pte_lemon:986265384992772166>"
            || v[0] == "三小"
            || v[0] == "公三小"
            || v[0] == "工三小"
            || v[0] == "這三小"
            || v[0] == "這到底三小"
            || v[0] == "我看了三小") {
            mt19937 mt(time(nullptr));
            string what = wat[mt() % size(wat)];
            dpp::message msg(event.msg.channel_id, what);
            bot.message_create(msg);
        }
        else if ((v[0] == "抽" || v[0] == "gacha") && (v[1] == "pcr" || v[1] == "公連")) {
            pcrgacha(v[2]);
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if ((v[0] == "抽" || v[0] == "gacha") && (v[1] == "fgo" || v[1] == "居歐")){
            fgogacha(v[2]);
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if ((v[0] == "抽" || v[0] == "gacha") && (v[1] == "ark" || v[1] == "方舟")) {
            arkgacha(v[2]);
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if ((v[0] == "抽到有") && (v[1] == "pcr" || v[1] == "公連")) {
            pcrget();
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if ((v[0] == "抽到有") && (v[1] == "fgo" || v[1] == "居歐")) {
            fgoget();
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "fgo機率" || v[0] == "fgo抽卡機率") {
            dpp::message msg(event.msg.channel_id, "銀卡<:fgo_K3:1107145411724054532> 96%\n金卡<:fgo_K2:1107145363795746977> 3%\n彩卡<:fgo_K1:1107145268681519114> 1%");
            bot.message_create(msg);
        }
        else if (v[0] == "方舟機率" || v[0] == "方舟抽卡機率") {
            dpp::message msg(event.msg.channel_id, "六星<:ark6:1107953803057188905> 2%\n五星<:ark5:1107953865602637824> 8%\n四星<:ark4:1107953907377901579> 30%\n三星<:ark3:1107953947353808947> 60%\n\n不要問我為什麼用狙信物，我絕對沒有對某隻六星狙有特別的偏好");
            bot.message_create(msg);
        }
        else if (v[0] == "pcr機率" || v[0] == "pcr抽卡機率" || v[0] == "公連機率" || v[0] == "公連抽卡機率") {
            dpp::message msg(event.msg.channel_id, "★★★角色　3%\n★★角色　  18%\n★角色　　 79%\n\n十抽功能中、第十抽有保底★★角色");
            bot.message_create(msg);
        }
        else if (v[0] == "亂數測試") {
            mt19937 mt(time(nullptr));
            string s = to_string(mt());
            dpp::message msg(event.msg.channel_id, s);
            bot.message_create(msg);
        }
        else if (v[0] == "抽卡說明") {
            gacha = "抽卡\n目前支援fgo、明日方舟與公主連結\nfgo與公主連結支援抽到有功能（有保底）\n\n抽卡功能使用公式\n抽 (這裡用中文或半形英文打遊戲名稱) (這裡用半形數字打抽數)\n\n抽卡公式說明\n抽字為觸發功能必要、也可輸入gacha一詞代替\n三個區段間請用半形空格隔開\n遊戲名稱可打pcr、fgo、ark、公連、方舟、居歐\n最後請打抽數，拜託不要用太大數字炸我機器人";
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        //以下是fgo素材查詢功能程式碼，結束有另一行告知
        else if (v[0] == "黨證" || v[0] == "英雄之證") {
            dpp::message msg(event.msg.channel_id, mat[0]);
            bot.message_create(msg);
        }
        else if (v[0] == "兇骨" || v[0] == "凶骨") {
            dpp::message msg(event.msg.channel_id, mat[1]);
            bot.message_create(msg);
        }
        else if (v[0] == "龍牙" || v[0] == "龍之牙") {
            dpp::message msg(event.msg.channel_id, mat[2]);
            bot.message_create(msg);
        }
        else if (v[0] == "塵" || v[0] == "虛影之塵" || v[0] == "灰塵" || v[0] == "塵土") {
            dpp::message msg(event.msg.channel_id, mat[3]);
            bot.message_create(msg);
        }
        else if (v[0] == "鎖" || v[0] == "愚者之鎖") {
            dpp::message msg(event.msg.channel_id, mat[4]);
            bot.message_create(msg);
        }
        else if (v[0] == "毒針" || v[0] == "萬死的毒針") {
        dpp::message msg(event.msg.channel_id, mat[5]);
        bot.message_create(msg);
        }
        else if (v[0] == "髓液" || v[0] == "魔術髓液") {
            dpp::message msg(event.msg.channel_id, mat[6]);
            bot.message_create(msg);
        }
        else if (v[0] == "鐵樁" || v[0] == "宵泣之鐵樁" || v[0] == "釘子") {
            dpp::message msg(event.msg.channel_id, mat[7]);
            bot.message_create(msg);
        }
        else if (v[0] == "火藥" || v[0] == "振盪火藥") {
            dpp::message msg(event.msg.channel_id, mat[8]);
            bot.message_create(msg);
        }
        else if (v[0] == "小鐘" || v[0] == "赦免的小鐘") {
            dpp::message msg(event.msg.channel_id, mat[9]);
            bot.message_create(msg);
        }
        else if (v[0] == "儀式劍" || v[0] == "黃昏の儀式劍") {
            dpp::message msg(event.msg.channel_id, mat[10]);
            bot.message_create(msg);
        }
        else if (v[0] == "忘れじの灰") {
            dpp::message msg(event.msg.channel_id, mat[11]);
            bot.message_create(msg);
        }
        else if (v[0] == "樹種" || v[0] == "世界樹之種") {
            dpp::message msg(event.msg.channel_id, mat[12]);
            bot.message_create(msg);
        }
        else if (v[0] == "提燈" || v[0] == "鬼魂提燈") {
            dpp::message msg(event.msg.channel_id, mat[13]);
            bot.message_create(msg);
        }
        else if (v[0] == "八連晶" || v[0] == "八連雙晶" || v[0] == "雙晶") {
            dpp::message msg(event.msg.channel_id, mat[14]);
            bot.message_create(msg);
        }
        else if (v[0] == "寶玉" || v[0] == "蛇之寶玉" || v[0] == "蛇玉") {
            dpp::message msg(event.msg.channel_id, mat[15]);
            bot.message_create(msg);
        }
        else if (v[0] == "羽毛" || v[0] == "鳳凰羽毛") {
            dpp::message msg(event.msg.channel_id, mat[16]);
            bot.message_create(msg);
        }
        else if (v[0] == "齒輪" || v[0] == "無間齒輪") {
            dpp::message msg(event.msg.channel_id, mat[17]);
            bot.message_create(msg);
        }
        else if (v[0] == "書頁" || v[0] == "禁斷書頁") {
            dpp::message msg(event.msg.channel_id, mat[18]);
            bot.message_create(msg);
        }
        else if (v[0] == "藥瓶" || v[0] == "人工生命體幼體") {
            dpp::message msg(event.msg.channel_id, mat[19]);
            bot.message_create(msg);
        }
        else if (v[0] == "馬蹄鐵" || v[0] == "隕蹄鐵") {
            dpp::message msg(event.msg.channel_id, mat[20]);
            bot.message_create(msg);
        }
        else if (v[0] == "勳章" || v[0] == "大騎士勳章") {
            dpp::message msg(event.msg.channel_id, mat[21]);
            bot.message_create(msg);
        }
        else if (v[0] == "貝殼" || v[0] == "追憶的貝殼") {
            dpp::message msg(event.msg.channel_id, mat[22]);
            bot.message_create(msg);
        }
        else if (v[0] == "玉" || v[0] == "枯淡勾玉") {
            dpp::message msg(event.msg.channel_id, mat[23]);
            bot.message_create(msg);
        }
        else if (v[0] == "冰" || v[0] == "永遠結冰") {
            dpp::message msg(event.msg.channel_id, mat[24]);
            bot.message_create(msg);
        }
        else if (v[0] == "指輪" || v[0] == "巨人的指輪") {
            dpp::message msg(event.msg.channel_id, mat[25]);
            bot.message_create(msg);
        }
        else if (v[0] == "極光鋼" || v[0] == "極光之鋼") {
            dpp::message msg(event.msg.channel_id, mat[26]);
            bot.message_create(msg);
        }
        else if (v[0] == "閑古鈴") {
            dpp::message msg(event.msg.channel_id, mat[27]);
            bot.message_create(msg);
        }
        else if (v[0] == "箭頭" || v[0] == "禍罪之箭頭") {
            dpp::message msg(event.msg.channel_id, mat[28]);
            bot.message_create(msg);
        }
        else if (v[0] == "光銀之冠") {
            dpp::message msg(event.msg.channel_id, mat[29]);
            bot.message_create(msg);
        }
        else if (v[0] == "神脈靈子") {
            dpp::message msg(event.msg.channel_id, mat[30]);
            bot.message_create(msg);
        }
        else if (v[0] == "線球" || v[0] == "虹色線球") {
            dpp::message msg(event.msg.channel_id, mat[31]);
            bot.message_create(msg);
        }
        else if (v[0] == "鱗粉" || v[0] == "夢幻的鱗粉") {
            dpp::message msg(event.msg.channel_id, mat[32]);
            bot.message_create(msg);
        }
        else if (v[0] == "爪" || v[0] == "爪子" || v[0] == "混沌之爪") {
            dpp::message msg(event.msg.channel_id, mat[33]);
            bot.message_create(msg);
        }
        else if (v[0] == "心臟" || v[0] == "蠻神心臟") {
            dpp::message msg(event.msg.channel_id, mat[34]);
            bot.message_create(msg);
        }
        else if (v[0] == "龍麟" || v[0] == "逆麟" || v[0] == "龍之逆麟") {
            dpp::message msg(event.msg.channel_id, mat[35]);
            bot.message_create(msg);
        }
        else if (v[0] == "精靈根") {
            dpp::message msg(event.msg.channel_id, mat[36]);
            bot.message_create(msg);
        }
        else if (v[0] == "角" || v[0] == "戰馬的幼角") {
            dpp::message msg(event.msg.channel_id, mat[37]);
            bot.message_create(msg);
        }
        else if (v[0] == "血石" || v[0] == "淚石" || v[0] == "血之淚石") {
            dpp::message msg(event.msg.channel_id, mat[38]);
            bot.message_create(msg);
        }
        else if (v[0] == "獸脂" || v[0] == "黑獸脂") {
            dpp::message msg(event.msg.channel_id, mat[39]);
            bot.message_create(msg);
        }
        else if (v[0] == "封魔之燈") {
            dpp::message msg(event.msg.channel_id, mat[40]);
            bot.message_create(msg);
        }
        else if (v[0] == "甲蟲" || v[0] == "智慧之聖甲蟲像") {
            dpp::message msg(event.msg.channel_id, mat[41]);
            bot.message_create(msg);
        }
        else if (v[0] == "胎毛" || v[0] == "獸毛" || v[0] == "起源的胎毛") {
            dpp::message msg(event.msg.channel_id, mat[42]);
            bot.message_create(msg);
        }
        else if (v[0] == "咒獸膽石") {
            dpp::message msg(event.msg.channel_id, mat[43]);
            bot.message_create(msg);
        }
        else if (v[0] == "神酒" || v[0] == "奇奇神酒") {
            dpp::message msg(event.msg.channel_id, mat[44]);
            bot.message_create(msg);
        }
        else if (v[0] == "爐心" || v[0] == "曉光爐心") {
            dpp::message msg(event.msg.channel_id, mat[45]);
            bot.message_create(msg);
        }
        else if (v[0] == "九十九鏡") {
            dpp::message msg(event.msg.channel_id, mat[46]);
            bot.message_create(msg);
        }
        else if (v[0] == "金蛋" || v[0] == "真理之卵") {
            dpp::message msg(event.msg.channel_id, mat[47]);
            bot.message_create(msg);
        }
        else if (v[0] == "煌星碎片") {
            dpp::message msg(event.msg.channel_id, mat[48]);
            bot.message_create(msg);
        }
        else if (v[0] == "悠久果實") {
            dpp::message msg(event.msg.channel_id, mat[49]);
            bot.message_create(msg);
        }
        else if (v[0] == "鬼炎鬼燈") {
            dpp::message msg(event.msg.channel_id, mat[50]);
            bot.message_create(msg);
        }
        //fgo素材查詢功能程式碼結束
    });

    /*
    bot.on_message_create([&bot](const dpp::message_create_t& event) {

        if (v[0] == "europe" 
         || v[0] == "歐" 
         || v[0] == "歐皇"
         || v[0] == "歐洲"
         || v[0] == "歐洲人") {
            mt19937 mt(time(nullptr));
            string eu = europe[mt() % size(europe)];  //https://github.com/Fate-Grand-Automata/FGA
            dpp::message msg(event.msg.channel_id, eu);
            bot.message_create(msg);
        }
        else if (v[0] == "<rs" 
            || v[0] == "!rs" 
            || v[0] == "<r" 
            || v[0] == "<osu"  
            || v[0] == "<recent" 
            || v[0] == "<compare") {
            dpp::message msg(event.msg.channel_id, "https://cdn.discordapp.com/attachments/933710044917288963/1092771938272805024/IMG_8429.jpg");
            bot.message_create(msg);
        }
        else if (v[0] == "fga") {
            dpp::message msg(event.msg.channel_id, "https://github.com/Fate-Grand-Automata/FGA");
            bot.message_create(msg);
        }
        else if (v[0] == "婆"
            || v[0] == "我婆"
            || v[0] == "這我婆"
            || v[0] == "又你婆") {
            dpp::message msg(event.msg.channel_id, "https://cdn.discordapp.com/attachments/966729542800658442/1092428172705931355/FB_IMG_1625811644856.jpg");
            bot.message_create(msg);
        }
        else if (v[0] == "true" 
            || v[0] == "確實" 
            || v[0] == "雀食") {
            mt19937 mt(time(nullptr));
            string tr = truee[mt() % size(truee)];
            dpp::message msg(event.msg.channel_id, tr);
            bot.message_create(msg);
        }
        else if (v[0] == "<:lao:1012343248095821914>" 
            || v[0] == "<:lao:1089079085327732738>" 
            || v[0] == "佬" 
            || v[0] == "大佬" 
            || v[0] == "老") {
            mt19937 mt(time(nullptr));
            string lao = dalao[mt() % size(dalao)];
            dpp::message msg(event.msg.channel_id, lao);
            bot.message_create(msg);
        }
        else if (v[0] == "<:kusa:1043444810259910748>" 
            || v[0] == "<:kusa:1080709220451745853>" 
            || v[0] == "草" 
            || v[0] == "笑死" 
            || v[0] == "笑" 
            || v[0] == "kusa" 
            || v[0] == "w" 
            || v[0] == "ww" 
            || v[0] == "www") {
            mt19937 mt(time(nullptr));
            string ku = kusa[mt() % size(kusa)];
            dpp::message msg(event.msg.channel_id, ku);
            bot.message_create(msg);
        }
        else if (v[0] == u8"🏳️‍🌈" 
            || v[0] == u8"🏳️‍🌈❓"
            || v[0] == "gay"
            || v[0] == "甲" 
            || v[0] == "給" 
            || v[0] == "你是甲" 
            || v[0] == "你是給" 
            || v[0] == u8"🈸") {
            mt19937 mt(time(nullptr));
            string gay = gaygay[mt() % size(gaygay)];
            dpp::message msg(event.msg.channel_id, gay);
            bot.message_create(msg);
        }
        else if (v[0] == u8"🚔"
            || v[0] == u8"🚓"
            || v[0] == "fbi"
            || v[0] == "ㄌㄌㄎ"
            || v[0] == "ㄈㄅㄌ"
            || v[0] == "你是ㄌㄌㄎ") {
            mt19937 mt(time(nullptr));
            string fbifbi = fbi[mt() % size(fbi)];
            dpp::message msg(event.msg.channel_id, fbifbi);
            bot.message_create(msg);
        }
        else if (v[0] == "雀" 
            || v[0] == "雀嗎" 
            || v[0] == "@雀士"
            || v[0] == "有人要雀嗎" 
            || v[0] == "現在有人要雀嗎" 
            || v[0] == "誰要雀" 
            || v[0] == "雀！") {
            dpp::message msg(event.msg.channel_id, "https://media.discordapp.net/attachments/988812288549093478/1099698505704022057/9F7E7973-93C7-4B07-9324-16D4BECC70A5.jpg");
            bot.message_create(msg);
        }
        else if (v[0] == "能" 
            || v[0] == "能天" 
            || v[0] == "阿能" 
            || v[0] == "能天使") {
            mt19937 mt(time(nullptr));
            string exu = exusiai[mt() % size(exusiai)];
            dpp::message msg(event.msg.channel_id, exu);
            bot.message_create(msg);
        }
        else if (v[0] == "尼祿" 
            || v[0] == "nero") {
            mt19937 mt(time(nullptr));
            string ner = nero[mt() % size(nero)];
            dpp::message msg(event.msg.channel_id, ner);
            bot.message_create(msg);
        }
        else if (v[0] == "瓜"
            || v[0] == "吃瓜") {
            dpp::message msg(event.msg.channel_id, "https://cdn.discordapp.com/attachments/503219154413682713/1107119476333350923/gcj_star230505.gif");
            bot.message_create(msg);
        }
        else if (v[0] == "bonk"
            || v[0] == "不可以瑟瑟"
            || v[0] == "不可以色色") {
            dpp::message msg(event.msg.channel_id, "<a:emoji_23:1008963509431840838>");
            bot.message_create(msg);
        }
        else if (v[0] == "JR去程"
            || v[0] == "jr去程"
            || v[0] == "去程"
            || v[0] == "沼津去程") {
            dpp::message msg(event.msg.channel_id, tokyotonumazu);
            bot.message_create(msg);
        }
        else if (v[0] == "JR回程"
            || v[0] == "jr回程"
            || v[0] == "回程"
            || v[0] == "沼津回程") {
            dpp::message msg(event.msg.channel_id, numazutotokyo);
            bot.message_create(msg);
        }
        else if (v[0] == "JR時刻"
            || v[0] == "jr時刻"
            || v[0] == "JR時刻查詢"
            || v[0] == "jr時刻查詢") {
            dpp::message msg(event.msg.channel_id, jrtime);
            bot.message_create(msg);
        }
        else if (v[0] == "<:Setsuna:1074672084132827237>"
            || v[0] == "<:Setsuna:1074672084132827237> <:Setsuna:1074672084132827237>"
            || v[0] == "<:Setsuna:1074672084132827237> <:Setsuna:1074672084132827237> <:Setsuna:1074672084132827237>"
            || v[0] == "<:Kyaru_confused:966726451636355112> "
            || v[0] == "<:Kyaru_confused:966726451636355112> <:Kyaru_confused:966726451636355112>"
            || v[0] == "<:Kyaru_confused:966726451636355112> <:Kyaru_confused:966726451636355112> <:Kyaru_confused:966726451636355112>"
            || v[0] == "<:pte_lemon:986265384992772166>"
            || v[0] == "<:pte_lemon:986265384992772166> <:pte_lemon:986265384992772166>"
            || v[0] == "<:pte_lemon:986265384992772166> <:pte_lemon:986265384992772166> <:pte_lemon:986265384992772166>"
            || v[0] == "三小"
            || v[0] == "公三小"
            || v[0] == "工三小"
            || v[0] == "這三小"
            || v[0] == "這到底三小"
            || v[0] == "我看了三小") {
            mt19937 mt(time(nullptr));
            string what = wat[mt() % size(wat)];
            dpp::message msg(event.msg.channel_id, what);
            bot.message_create(msg);
        }
        // 以下是抽卡程式碼
        else if (v[0] == "fgo抽" || v[0] == "fgo單抽" || v[0] == "人類惡抽" || v[0] == "人類惡單抽") {
            mt19937 mt(time(nullptr));
            int r = mt() % 100;
            string gacha = "";

                switch (r) {
                case 27:
                    gacha = "<:fgo_K1:1107145268681519114>"; //彩卡
                    break;

                case 35: case 98: case 65:
                    gacha = "<:fgo_K2:1107145363795746977>"; //金卡
                    break;

                default:
                    gacha = "<:fgo_K3:1107145411724054532>"; //銀卡
                    break;
                }

            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "fgo十抽" || v[0] == "fgo十連抽" || v[0] == "人類惡十抽" || v[0] == "人類惡十連抽") {
            string gacha = "";
            mt19937 mt(time(nullptr));

                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 5; j++) {
                        int r = mt() % 100;

                        switch (r) {
                        case 27:
                            gacha += "<:fgo_K1:1107145268681519114>";
                            break;

                        case 35: case 98: case 65:
                            gacha += "<:fgo_K2:1107145363795746977>";
                            break;

                        default:
                            gacha += "<:fgo_K3:1107145411724054532>";
                            break;
                        }
                    }
                    gacha += " \n";
                }
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "fgo百抽" || v[0] == "fgo百連抽" || v[0] == "人類惡百抽" || v[0] == "人類惡百連抽") {
            int fgoga[3] = {0};
            mt19937 mt(time(nullptr));

            for (int k = 0; k < 100; k++) {
                int r = mt() % 100;

                switch (r) {
                case 47:
                    fgoga[0]++;
                    break;

                case 85: case 98: case 6:
                    fgoga[1]++;
                    break;

                default:
                    fgoga[2]++;
                    break;
                }
            }

            string silver = to_string(fgoga[2]);
            string golden = to_string(fgoga[1]);
            string rainbow = to_string(fgoga[0]);
            string gacha = "一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n" + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n";

            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "fgo抽到有" || v[0] == "人類惡抽到有") {
            int fgoga[3] = { 0 };
            int k = 0;
            mt19937 mt(time(nullptr));

            while(fgoga[0] == 0 && k < 329) {
                int r = mt() % 100;

                switch (r) {
                case 47:
                    fgoga[0]++;
                    break;

                case 85: case 98: case 6:
                    fgoga[1]++;
                    break;

                default:
                    fgoga[2]++;
                    break;
                }
                k++;
            }

            string times = to_string(k);
            string silver = to_string(fgoga[2]);
            string golden = to_string(fgoga[1]);
            string rainbow = to_string(fgoga[0]);
            string gacha = "";

            if (k < 329)
                gacha = "一共抽了" + times + "抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n" + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n";
            else
                gacha = "一共抽了330抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n" + golden + "張金卡<:fgo_K2:1107145363795746977>\n1張彩卡<:fgo_K1:1107145268681519114>\n";
            
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "方舟抽" || v[0] == "方舟單抽" || v[0] == "驢子抽" || v[0] == "驢子單抽") {
            string gacha = "";
            mt19937 mt(time(nullptr));
            int r = mt() % 50;

            switch (r) {
            case 27:  //六星
                gacha += "<:ark6:1107953803057188905>";
                break;

            case 35: case 43: case 15: case 1:  //五星
                gacha += "<:ark5:1107953865602637824>";
                break;

            case 5: case 29: case 45: case 18: case 20: case 3: case 26: case 48: case 32: case 40: case 39: case 16: case 8: case 36: case 4:  //四星
                gacha += "<:ark4:1107953907377901579>";
                break;

            default:  //三星
                gacha += "<:ark3:1107953947353808947>";
                break;
            }
           
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "方舟十抽" || v[0] == "方舟十連抽" || v[0] == "驢子十抽" || v[0] == "驢子十連抽") {
            string gacha = "";
            mt19937 mt(time(nullptr));

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 5; j++) {
                    int r = mt() % 50;

                    switch (r) {
                    case 27:  //六星
                        gacha += "<:ark6:1107953803057188905>";
                        break;

                    case 35: case 43: case 15: case 1:  //五星
                        gacha += "<:ark5:1107953865602637824>";
                        break;

                    case 5: case 29: case 45: case 18: case 20: case 3: case 26: case 48: case 32: case 40: case 39: case 16: case 8: case 36: case 4:  //四星
                        gacha += "<:ark4:1107953907377901579>";
                        break;

                    default:  //三星
                        gacha += "<:ark3:1107953947353808947>";
                        break;
                    }
                }
                gacha += " \n";
            }
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "方舟百抽" || v[0] == "方舟百連抽" || v[0] == "驢子百抽" || v[0] == "驢子百連抽") {
            mt19937 mt(time(nullptr));
            int arkga[4] = { 0 };

            for (int i = 0; i < 100; i++) {
                int r = mt() % 50;

                switch (r) {
                case 27:  //六星
                    arkga[0]++;
                    break;

                case 35: case 43: case 15: case 1:  //五星
                    arkga[1]++;
                    break;

                case 5: case 29: case 45: case 18: case 20: case 3: case 26: case 48: case 32: case 40: case 39: case 16: case 8: case 21: case 4:  //四星
                    arkga[2]++;
                    break;

                default:  //三星
                    arkga[3]++;
                    break;
                }
            }
            string bronze = to_string(arkga[3]);
            string silver = to_string(arkga[2]);
            string golden = to_string(arkga[1]);
            string rainbow = to_string(arkga[0]);
            string gacha = "一共抽到了：\n" + bronze + "張三星<:ark3:1107953947353808947>\n" + silver + "張四星<:ark4:1107953907377901579>\n" + golden + "張五星<:ark5:1107953865602637824>\n" + rainbow + "張六星<:ark6:1107953803057188905>\n";

            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "pcr抽" || v[0] == "pcr單抽" || v[0] == "公連抽" || v[0] == "公連單抽") {
            mt19937 mt(time(nullptr));
            int r = mt() % 33;
            string gacha = "";

            switch (r) {
            case 27:
                gacha = "<:pcr3:1117798715957194923>"; //彩卡
                break;

            case 15: case 31: case 6:
                gacha = "<:pcr2:1117798436427804754>"; //金卡
                break;

            default:
                gacha = "<:pcr1:1117798654548377641>"; //銀卡
                break;
            }

            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "pcr十抽"|| v[0] == "公連十抽" || v[0] == "公連十連") {
            mt19937 mt(time(nullptr));
            string gacha = "";

            for (int i = 0; i < 5; i++) {
                int r = mt() % 33;
                switch (r) {
                case 27:
                    gacha += "<:pcr3:1117798715957194923>"; //彩卡
                    break;

                case 15: case 31: case 6:
                    gacha += "<:pcr2:1117798436427804754>"; //金卡
                    break;

                default:
                    gacha += "<:pcr1:1117798654548377641>"; //銀卡
                    break;
                }
            }
            gacha += "\n";
            for (int j = 0; j < 4; j++) {
                int r = mt() % 33;
                switch (r) {
                case 27:
                    gacha += "<:pcr3:1117798715957194923>"; //彩卡
                    break;

                case 15: case 31: case 6:
                    gacha += "<:pcr2:1117798436427804754>"; //金卡
                    break;

                default:
                    gacha += "<:pcr1:1117798654548377641>"; //銀卡
                    break;
                }
            }
            int r = mt() % 33;
            switch (r) {
            case 27:
                gacha += "<:pcr3:1117798715957194923>"; //彩卡
                break;

            default:
                gacha += "<:pcr2:1117798436427804754>"; //金卡
                break;
            }

            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "<:pcr1:1117798654548377641><:pcr1:1117798654548377641><:pcr1:1117798654548377641><:pcr1:1117798654548377641><:pcr1:1117798654548377641>\n<:pcr1:1117798654548377641><:pcr1:1117798654548377641><:pcr1:1117798654548377641><:pcr1:1117798654548377641><:pcr2:1117798436427804754>") {
            dpp::message msg(event.msg.channel_id, "哈哈笑死+19可憐哪");
            bot.message_create(msg);
        }
        else if (v[0] == "pcr百抽" || v[0] == "pcr百連抽" || v[0] == "公連百抽" || v[0] == "公連百連抽") {
            int pcrga[3] = {0};
            mt19937 mt(time(nullptr));

            for (int k = 0; k < 100; k++) {
                int r = mt() % 33;

                switch (r) {
                case 27:
                    pcrga[0]++;
                    break;

                case 15: case 9: case 31:
                    pcrga[1]++;
                    break;

                default:
                    pcrga[2]++;
                    break;
                }
            }

            string silver = to_string(pcrga[2]);
            string golden = to_string(pcrga[1]);
            string rainbow = to_string(pcrga[0]);
            string gacha = "一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n" + golden + "張金卡<:pcr2:1117798436427804754>\n" + rainbow + "張彩卡<:pcr3:1117798715957194923>\n";

            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "pcr100抽"|| v[0] == "公連100抽") {
            int pcrga[3] = {0};
            mt19937 mt(time(nullptr));

            for (int k = 0; k < 100; k++) {
                int r = mt() % 33;

                switch (r) {
                case 27:
                    pcrga[0]++;
                    break;

                case 15: case 9: case 31:
                    pcrga[1]++;
                    break;

                default:
                    pcrga[2]++;
                    break;
                }
            }

            string silver = to_string(pcrga[2]);
            string golden = to_string(pcrga[1]);
            string rainbow = to_string(pcrga[0]);
            string gacha = "一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n" + golden + "張金卡<:pcr2:1117798436427804754>\n" + rainbow + "張彩卡<:pcr3:1117798715957194923>\n";

            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "pcr抽到有" || v[0] == "公連抽到有") {
            int pcrga[3] = { 0 };
            int k = 0;
            mt19937 mt(time(nullptr));

            while(pcrga[0] == 0 && k < 199) {
                int r = mt() % 33;

                switch (r) {
                case 27:
                    pcrga[0]++;
                    break;

                case 15: case 9: case 31:
                    pcrga[1]++;
                    break;

                default:
                    pcrga[2]++;
                    break;
                }
                k++;
            }

            string silver = to_string(pcrga[2]);
            string golden = to_string(pcrga[1]);
            string rainbow = to_string(pcrga[0]);
            string gacha = "";

            if (pcrga[0] == 0)
                gacha = "一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n" + golden + "張金卡<:pcr2:1117798436427804754>\n1張彩卡<:pcr3:1117798715957194923>\n";
            else
                gacha = "一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n" + golden + "張金卡<:pcr2:1117798436427804754>\n" + rainbow + "張彩卡<:pcr3:1117798715957194923>\n";
            
            dpp::message msg(event.msg.channel_id, gacha);
            bot.message_create(msg);
        }
        else if (v[0] == "fgo機率" || v[0] == "fgo抽卡機率") {
            dpp::message msg(event.msg.channel_id, "銀卡<:fgo_K3:1107145411724054532> 96%\n金卡<:fgo_K2:1107145363795746977> 3%\n彩卡<:fgo_K1:1107145268681519114> 1%");
            bot.message_create(msg);
        }
        else if (v[0] == "方舟機率" || v[0] == "方舟抽卡機率") {
            dpp::message msg(event.msg.channel_id, "六星<:ark6:1107953803057188905> 2%\n五星<:ark5:1107953865602637824> 8%\n四星<:ark4:1107953907377901579> 30%\n三星<:ark3:1107953947353808947> 60%\n\n不要問我為什麼用狙信物，我絕對沒有對某隻六星狙有特別的偏好");
            bot.message_create(msg);
        }
        else if (v[0] == "pcr機率" || v[0] == "pcr抽卡機率" || v[0] == "公連機率" || v[0] == "公連抽卡機率") {
            dpp::message msg(event.msg.channel_id, "★★★角色　3%\n★★角色　  18%\n★角色　　 79%\n\n十抽功能中、第十抽有保底★★角色");
            bot.message_create(msg);
        }
        else if (v[0] == "亂數測試") {
            mt19937 mt(time(nullptr));
            string s = to_string(mt());
            dpp::message msg(event.msg.channel_id, s);
            bot.message_create(msg);
        }
        else if (v[0] == "t e s t") {
            string s = v[0];

            vector<string> v;

            while (1) {
                v.push_back(s.substr(0, s.find(" "))); // 從第一個空白分割出左側子字串放入vector
                s = s.substr(s.find(" ") + 1, s.length()); // 從第一個空白分割出右側子字串設為s

                // 取得最後一個字。最後一個字找不到空白了
                if (s.find(" ") == -1) {
                    v.push_back(s);
                    break;
                }
            }

            cout << v.size() << endl; // 3
            cout << v[0] << endl;     // hello
            cout << v[1] << endl;     // world
            cout << v[2] << endl;     // jenny
        }
        //以下是fgo素材查詢功能程式碼，結束有另一行告知

        else if (v[0] == "黨證" || v[0] == "英雄之證") {
            dpp::message msg(event.msg.channel_id, mat[0]);
            bot.message_create(msg);
        }
        else if (v[0] == "兇骨" || v[0] == "凶骨") {
            dpp::message msg(event.msg.channel_id, mat[1]);
            bot.message_create(msg);
        }
        else if (v[0] == "龍牙" || v[0] == "龍之牙") {
            dpp::message msg(event.msg.channel_id, mat[2]);
            bot.message_create(msg);
        }
        else if (v[0] == "塵" || v[0] == "虛影之塵" || v[0] == "灰塵" || v[0] == "塵土") {
            dpp::message msg(event.msg.channel_id, mat[3]);
            bot.message_create(msg);
        }
        else if (v[0] == "鎖" || v[0] == "愚者之鎖") {
            dpp::message msg(event.msg.channel_id, mat[4]);
            bot.message_create(msg);
        }
        else if (v[0] == "毒針" || v[0] == "萬死的毒針") {
        dpp::message msg(event.msg.channel_id, mat[5]);
        bot.message_create(msg);
        }
        else if (v[0] == "髓液" || v[0] == "魔術髓液") {
            dpp::message msg(event.msg.channel_id, mat[6]);
            bot.message_create(msg);
        }
        else if (v[0] == "鐵樁" || v[0] == "宵泣之鐵樁" || v[0] == "釘子") {
            dpp::message msg(event.msg.channel_id, mat[7]);
            bot.message_create(msg);
        }
        else if (v[0] == "火藥" || v[0] == "振盪火藥") {
            dpp::message msg(event.msg.channel_id, mat[8]);
            bot.message_create(msg);
        }
        else if (v[0] == "小鐘" || v[0] == "赦免的小鐘") {
            dpp::message msg(event.msg.channel_id, mat[9]);
            bot.message_create(msg);
        }
        else if (v[0] == "儀式劍" || v[0] == "黃昏の儀式劍") {
            dpp::message msg(event.msg.channel_id, mat[10]);
            bot.message_create(msg);
        }
        else if (v[0] == "忘れじの灰") {
            dpp::message msg(event.msg.channel_id, mat[11]);
            bot.message_create(msg);
        }
        else if (v[0] == "樹種" || v[0] == "世界樹之種") {
            dpp::message msg(event.msg.channel_id, mat[12]);
            bot.message_create(msg);
        }
        else if (v[0] == "提燈" || v[0] == "鬼魂提燈") {
            dpp::message msg(event.msg.channel_id, mat[13]);
            bot.message_create(msg);
        }
        else if (v[0] == "八連晶" || v[0] == "八連雙晶" || v[0] == "雙晶") {
            dpp::message msg(event.msg.channel_id, mat[14]);
            bot.message_create(msg);
        }
        else if (v[0] == "寶玉" || v[0] == "蛇之寶玉" || v[0] == "蛇玉") {
            dpp::message msg(event.msg.channel_id, mat[15]);
            bot.message_create(msg);
        }
        else if (v[0] == "羽毛" || v[0] == "鳳凰羽毛") {
            dpp::message msg(event.msg.channel_id, mat[16]);
            bot.message_create(msg);
        }
        else if (v[0] == "齒輪" || v[0] == "無間齒輪") {
            dpp::message msg(event.msg.channel_id, mat[17]);
            bot.message_create(msg);
        }
        else if (v[0] == "書頁" || v[0] == "禁斷書頁") {
            dpp::message msg(event.msg.channel_id, mat[18]);
            bot.message_create(msg);
        }
        else if (v[0] == "藥瓶" || v[0] == "人工生命體幼體") {
            dpp::message msg(event.msg.channel_id, mat[19]);
            bot.message_create(msg);
        }
        else if (v[0] == "馬蹄鐵" || v[0] == "隕蹄鐵") {
            dpp::message msg(event.msg.channel_id, mat[20]);
            bot.message_create(msg);
        }
        else if (v[0] == "勳章" || v[0] == "大騎士勳章") {
            dpp::message msg(event.msg.channel_id, mat[21]);
            bot.message_create(msg);
        }
        else if (v[0] == "貝殼" || v[0] == "追憶的貝殼") {
            dpp::message msg(event.msg.channel_id, mat[22]);
            bot.message_create(msg);
        }
        else if (v[0] == "玉" || v[0] == "枯淡勾玉") {
            dpp::message msg(event.msg.channel_id, mat[23]);
            bot.message_create(msg);
        }
        else if (v[0] == "冰" || v[0] == "永遠結冰") {
            dpp::message msg(event.msg.channel_id, mat[24]);
            bot.message_create(msg);
        }
        else if (v[0] == "指輪" || v[0] == "巨人的指輪") {
            dpp::message msg(event.msg.channel_id, mat[25]);
            bot.message_create(msg);
        }
        else if (v[0] == "極光鋼" || v[0] == "極光之鋼") {
            dpp::message msg(event.msg.channel_id, mat[26]);
            bot.message_create(msg);
        }
        else if (v[0] == "閑古鈴") {
            dpp::message msg(event.msg.channel_id, mat[27]);
            bot.message_create(msg);
        }
        else if (v[0] == "箭頭" || v[0] == "禍罪之箭頭") {
            dpp::message msg(event.msg.channel_id, mat[28]);
            bot.message_create(msg);
        }
        else if (v[0] == "光銀之冠") {
            dpp::message msg(event.msg.channel_id, mat[29]);
            bot.message_create(msg);
        }
        else if (v[0] == "神脈靈子") {
            dpp::message msg(event.msg.channel_id, mat[30]);
            bot.message_create(msg);
        }
        else if (v[0] == "線球" || v[0] == "虹色線球") {
            dpp::message msg(event.msg.channel_id, mat[31]);
            bot.message_create(msg);
        }
        else if (v[0] == "鱗粉" || v[0] == "夢幻的鱗粉") {
            dpp::message msg(event.msg.channel_id, mat[32]);
            bot.message_create(msg);
        }
        else if (v[0] == "爪" || v[0] == "爪子" || v[0] == "混沌之爪") {
            dpp::message msg(event.msg.channel_id, mat[33]);
            bot.message_create(msg);
        }
        else if (v[0] == "心臟" || v[0] == "蠻神心臟") {
            dpp::message msg(event.msg.channel_id, mat[34]);
            bot.message_create(msg);
        }
        else if (v[0] == "龍麟" || v[0] == "逆麟" || v[0] == "龍之逆麟") {
            dpp::message msg(event.msg.channel_id, mat[35]);
            bot.message_create(msg);
        }
        else if (v[0] == "精靈根") {
            dpp::message msg(event.msg.channel_id, mat[36]);
            bot.message_create(msg);
        }
        else if (v[0] == "角" || v[0] == "戰馬的幼角") {
            dpp::message msg(event.msg.channel_id, mat[37]);
            bot.message_create(msg);
        }
        else if (v[0] == "血石" || v[0] == "淚石" || v[0] == "血之淚石") {
            dpp::message msg(event.msg.channel_id, mat[38]);
            bot.message_create(msg);
        }
        else if (v[0] == "獸脂" || v[0] == "黑獸脂") {
            dpp::message msg(event.msg.channel_id, mat[39]);
            bot.message_create(msg);
        }
        else if (v[0] == "封魔之燈") {
            dpp::message msg(event.msg.channel_id, mat[40]);
            bot.message_create(msg);
        }
        else if (v[0] == "甲蟲" || v[0] == "智慧之聖甲蟲像") {
            dpp::message msg(event.msg.channel_id, mat[41]);
            bot.message_create(msg);
        }
        else if (v[0] == "胎毛" || v[0] == "獸毛" || v[0] == "起源的胎毛") {
            dpp::message msg(event.msg.channel_id, mat[42]);
            bot.message_create(msg);
        }
        else if (v[0] == "咒獸膽石") {
            dpp::message msg(event.msg.channel_id, mat[43]);
            bot.message_create(msg);
        }
        else if (v[0] == "神酒" || v[0] == "奇奇神酒") {
            dpp::message msg(event.msg.channel_id, mat[44]);
            bot.message_create(msg);
        }
        else if (v[0] == "爐心" || v[0] == "曉光爐心") {
            dpp::message msg(event.msg.channel_id, mat[45]);
            bot.message_create(msg);
        }
        else if (v[0] == "九十九鏡") {
            dpp::message msg(event.msg.channel_id, mat[46]);
            bot.message_create(msg);
        }
        else if (v[0] == "金蛋" || v[0] == "真理之卵") {
            dpp::message msg(event.msg.channel_id, mat[47]);
            bot.message_create(msg);
        }
        else if (v[0] == "煌星碎片") {
            dpp::message msg(event.msg.channel_id, mat[48]);
            bot.message_create(msg);
        }
        else if (v[0] == "悠久果實") {
            dpp::message msg(event.msg.channel_id, mat[49]);
            bot.message_create(msg);
        }
        else if (v[0] == "鬼炎鬼燈") {
            dpp::message msg(event.msg.channel_id, mat[50]);
            bot.message_create(msg);
        }
        //fgo素材查詢功能程式碼結束
    });*/


    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        if (event.msg.content == "!creator") {

            /* create the embed */
            dpp::embed embed = dpp::embed().
                set_color(dpp::colors::sti_blue).
                set_title("CREATOR").
                set_url("https://www.youtube.com/channel/UC04oBjEp3AKCMVMJAumw0oA").
                set_author("anime.photos.tw", "https://idol.st/allstars/cards", "https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                set_description("Yuuki Sutsuna is my waifu").
                set_thumbnail("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                add_field(
                    "感謝交大資工仔 @H1de_on_bruH 提供技術指導",
                    "給辛苦的創作者一點流量跟感謝吧"
                ).
                add_field(
                    "這隻機器人他老杯很難過",
                    "燈燈退役了"
                ).
                set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                set_footer(dpp::embed_footer().set_text("Some footer text here").set_icon("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png")).
                set_timestamp(time(0));

            /* reply with the created embed */
            bot.message_create(dpp::message(event.msg.channel_id, embed).set_reference(event.msg.id));
        }
        else if (event.msg.content == "!help" || event.msg.content == "!function" || event.msg.content == "!functions") {

            /* create the embed */
            dpp::embed embed = dpp::embed().
                set_color(dpp::colors::sti_blue).
                set_title("function").
                set_url("https://www.youtube.com/channel/UC04oBjEp3AKCMVMJAumw0oA").
                set_author("anime.photos.tw", "https://idol.st/allstars/cards", "https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                set_description("優木雪菜我婆！").
                set_thumbnail("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                add_field(
                    "可用斜線指令",
                    "new waifu \ncattie \nnero \nbruh \nexusiai \n"
                ).
                add_field(
                    "! 指令",
                    "help \ncreator \nbutton \n"
                ).
                add_field(
                    "^ 指令",
                    "支援n站車號與pixiv圖片編號"
                ).
                add_field(
                    "抽卡",
                    "目前支援fgo、明日方舟與公主連結\nfgo與公主連結支援抽到有功能（有保底）"
                ).
                add_field(
                    "抽卡功能使用公式",
                    "抽 (這裡用中文或半形英文打遊戲名稱) (這裡用半形數字打抽數)"
                ).
                add_field(
                    "抽卡公式說明",
                    "抽字為觸發功能必要、也可輸入gacha一詞代替\n三個區段間請用半形空格隔開\n遊戲名稱可打pcr、fgo、ark、公連、方舟、居歐\n最後請打抽數，拜託不要用太大數字炸我機器人"
                ).
                add_field(
                    "fgo素材掉落關卡查詢",
                    "輸入素材暱稱或全名都可以\n"
                ).
                add_field(
                    "回應",
                    "對特定文字及表情符號\n"
                ).
                add_field(
                    "最後更新日期",
                    "2023/6/23"
                ).
                set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                set_footer(dpp::embed_footer().set_text("Some footer text here").set_icon("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png")).
                set_timestamp(time(0));

            /* reply with the created embed */
            bot.message_create(dpp::message(event.msg.channel_id, embed).set_reference(event.msg.id));
        }
        else if (event.msg.content == "!button") {
            /* Create a message containing an action row, and a button within the action row. */
            bot.message_create(
                dpp::message(event.msg.channel_id, "this text has buttons").add_component(
                    dpp::component().add_component(
                        dpp::component().set_label("Click me!").
                        set_type(dpp::cot_button).
                        set_emoji(u8"😄").
                        set_style(dpp::cos_danger).
                        set_id("測試中")
                    )
                )
            );
        }
        else if (event.msg.content == "!select") {
            /* Create a message containing an action row, and a select menu within the action row. */
            dpp::message m(event.msg.channel_id, "this text has a select menu");
            m.add_component(
                dpp::component().add_component(
                    dpp::component().set_type(dpp::cot_selectmenu).
                    set_placeholder("Pick something").
                    add_select_option(dpp::select_option("label1", "value1", "description1").set_emoji(u8"😄")).
                    add_select_option(dpp::select_option("label2", "value2", "description2").set_emoji(u8"🙂")).
                    set_id("myselid")
                )
            );
            bot.message_create(m);
        }
        });

    //When a user clicks your button, the on_button_click event will fire, containing the custom_id you defined in your button.
    bot.on_button_click([&bot](const dpp::button_click_t & event) {
        // Button clicks are still interactions, and must be replied to in some form to prevent the "this interaction has failed" message from Discord to the user.
        event.reply("You clicked " + event.custom_id);
        });

    bot.start(dpp::st_wait);
    return 0;
}

