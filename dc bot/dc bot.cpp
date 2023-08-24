//#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <dpp/dpp.h>
#include <random>
#include <fstream>
#include <ctime>

using namespace std;
using namespace dpp;
using json = nlohmann::json;

string arkcr[124] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1092538926687858828/1680551962912.jpg",
    "https://media.discordapp.net/attachments/968693698206519356/1092538926914359466/1680551964443.jpg?width=1050&height=735",
    "https://cdn.discordapp.com/attachments/968693698206519356/1092709412789030972/16051910383634.png",
    "https://www.pixiv.net/artworks/70027330",
    "https://www.pixiv.net/artworks/96878578",  // 5
    "https://www.pixiv.net/artworks/106295232" ,
    "https://www.pixiv.net/artworks/100877791" ,
    "https://www.pixiv.net/artworks/106192093" ,
    "https://www.pixiv.net/artworks/106416803" ,
    "https://www.pixiv.net/artworks/100508530" ,  // 10
    "https://www.pixiv.net/artworks/98878276" ,
    "https://www.pixiv.net/artworks/71238969" ,
    "https://www.pixiv.net/artworks/90495379" ,
    "https://www.pixiv.net/artworks/89517369" ,
    "https://www.pixiv.net/artworks/67090381" ,  // 15
    "https://www.pixiv.net/artworks/91937298",
    "https://www.pixiv.net/artworks/74751807",
    "https://www.pixiv.net/artworks/81213258",
    "https://www.pixiv.net/artworks/85062679",
    "https://www.pixiv.net/artworks/110582149",  //  20
    "https://www.pixiv.net/artworks/74871383",
    "https://www.pixiv.net/artworks/79067802",
    "https://www.pixiv.net/artworks/79640496",
    "https://www.pixiv.net/artworks/101872504",
    "https://www.pixiv.net/artworks/105525478",  // 25
    "https://www.pixiv.net/artworks/103486827",
    "https://www.pixiv.net/artworks/105829323",
    "https://www.pixiv.net/artworks/101933810",
    "https://www.pixiv.net/artworks/104753423",
    "https://www.pixiv.net/artworks/99347539",  // 30
    "https://www.pixiv.net/artworks/83439562",
    "https://www.pixiv.net/artworks/93266233",
    "https://www.pixiv.net/artworks/91879173",
    "https://www.pixiv.net/artworks/103866984",
    "https://www.pixiv.net/artworks/101028272",  // 35
    "https://www.pixiv.net/artworks/102634213",
    "https://www.pixiv.net/artworks/79405727",
    "https://www.pixiv.net/artworks/105116769",
    "https://www.pixiv.net/artworks/101872743",
    "https://www.pixiv.net/artworks/104348996",  // 40
    "https://www.pixiv.net/artworks/91809487",
    "https://www.pixiv.net/artworks/97693106",
    "https://www.pixiv.net/artworks/87451043",
    "https://www.pixiv.net/artworks/105844530",
    "https://www.pixiv.net/artworks/75387374",  // 45
    "https://www.pixiv.net/artworks/82169692",
    "https://www.pixiv.net/artworks/106220663",
    "https://www.pixiv.net/artworks/101931248",
    "https://www.pixiv.net/artworks/93447113",
    "https://www.pixiv.net/artworks/107951126",  // 50
    "https://www.pixiv.net/artworks/86343437",
    "https://www.pixiv.net/artworks/89266819",
    "https://www.pixiv.net/artworks/106803939",
    "https://www.pixiv.net/artworks/79779657",
    "https://www.pixiv.net/artworks/74751807",  // 55
    "https://www.pixiv.net/artworks/101923676",
    "https://www.pixiv.net/artworks/87692502",
    "https://www.pixiv.net/artworks/84329196",
    "https://www.pixiv.net/artworks/77323551",
    "https://www.pixiv.net/artworks/77208163",  //  60
    "https://www.pixiv.net/artworks/85353549",
    "https://www.pixiv.net/artworks/86053423",
    "https://www.pixiv.net/artworks/86037415",
    "https://www.pixiv.net/artworks/79258674",
    "https://www.pixiv.net/artworks/82160090"  //  65
    "https://www.pixiv.net/artworks/108413770",
    "https://www.pixiv.net/artworks/108018284",
    "https://www.pixiv.net/artworks/109092104",
    "https://www.pixiv.net/artworks/107234037",
    "https://www.pixiv.net/artworks/105353416",  //  70
    "https://www.pixiv.net/artworks/105353416",
    "https://www.pixiv.net/artworks/102890589",
    "https://www.pixiv.net/artworks/98795930",
    "https://www.pixiv.net/artworks/98849187",
    "https://www.pixiv.net/artworks/98650893",  //  75
    "https://www.pixiv.net/artworks/108372225",
    "https://www.pixiv.net/artworks/107330774",
    "https://www.pixiv.net/artworks/108345276",
    "https://www.pixiv.net/artworks/109181283",
    "https://www.pixiv.net/artworks/98898181",  //  80
    "https://www.pixiv.net/artworks/109192813",
    "https://www.pixiv.net/artworks/109157386",
    "https://www.pixiv.net/artworks/101702064",
    "https://www.pixiv.net/artworks/107121238",
    "https://www.pixiv.net/artworks/106968058",  //  85
    "https://www.pixiv.net/artworks/106179650",
    "https://www.pixiv.net/artworks/91342692",
    "https://www.pixiv.net/artworks/110712914",
    "https://www.pixiv.net/artworks/100535122",
    "https://www.pixiv.net/artworks/98475526",  //  90
    "https://www.pixiv.net/artworks/110664627",
    "https://www.pixiv.net/artworks/102913001",
    "https://www.pixiv.net/artworks/109607317",
    "https://www.pixiv.net/artworks/95699940",
    "https://www.pixiv.net/artworks/110582149",  //  95
    "https://www.pixiv.net/artworks/110597319",
    "https://www.pixiv.net/artworks/107439143",
    "https://www.pixiv.net/artworks/95534968",
    "https://www.pixiv.net/artworks/110008745",
    "https://www.pixiv.net/artworks/109898769",  //  100
    "https://www.pixiv.net/artworks/110597319",
    "https://www.pixiv.net/artworks/109740570",
    "https://www.pixiv.net/artworks/110161097",
    "https://www.pixiv.net/artworks/101262774",
    "https://www.pixiv.net/artworks/105168923",  //  105
    "https://www.pixiv.net/artworks/109607317",
    "https://www.pixiv.net/artworks/99638814",
    "https://www.pixiv.net/artworks/109826719",
    "https://www.pixiv.net/artworks/110484344",
    "https://www.pixiv.net/artworks/106334195",  //  110
    "https://www.pixiv.net/artworks/106884972",
    "https://www.pixiv.net/artworks/90436390",
    "https://www.pixiv.net/artworks/103936727",
    "https://www.pixiv.net/artworks/105257460",
    "https://www.pixiv.net/artworks/102117373",  //  115
    "https://www.pixiv.net/artworks/89401257",
    "https://www.pixiv.net/artworks/101416704",
    "https://www.pixiv.net/artworks/109104100",
    "https://www.pixiv.net/artworks/108492583",
    "https://www.pixiv.net/artworks/98738304",  //  120
    "https://www.pixiv.net/artworks/110710689",
    "https://www.pixiv.net/artworks/106907485",
    "https://www.pixiv.net/artworks/81170525",
    "https://www.pixiv.net/artworks/80293330",
    "https://www.pixiv.net/artworks/95993983"  //  125
};
string dalao[12] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600372762808330/65bbfd846d3437b0dd9ed947dcc4816f.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600521085976576/1586869262198.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600614879010827/1619758952948.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600682138882138/1578841721163.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600776976269343/1636001561524.png",  // 5
    "https://cdn.discordapp.com/attachments/968693698206519356/1103600885793300480/1574742490553.png",
    "https://cdn.discordapp.com/attachments/966719485438476318/1103622392288399390/IMG_6535.GIF",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599188410880030/FB_IMG_1667864424847.jpg",
    "https://cdn.discordapp.com/attachments/968693698206519356/1108599543236399144/FB_IMG_1664012145347.jpg",
    "https://cdn.discordapp.com/attachments/988843667479470130/1109721623147331604/kitten-cat.gif", //  10
    "https://media.discordapp.net/attachments/727443536085254186/883883935141101589/image0.gif?width=87&height=87",
    "https://cdn.discordapp.com/attachments/968693698206519356/1126812896425431110/4qBl31563R.gif"
};
string europe[9] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601634916966471/64819726415fa4d795ccc6269f6e560b.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601681616347206/1604671763242.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601790546620416/Z.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1103601842497273947/2Q.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1105809939575865344/gif21.gif",  // 5
    "我沒差啊\n你們都這樣\n我習慣了阿\n\n\
你們在曬的時候有考慮過我的感受嗎？\n沒有阿\n從以前到現在一直以來都沒有阿\n\n\
阿我就是非洲阿\n什麼幾抽寶幾\n我現在都不在意了\n就連那個未持有\n我現在都已經懶得理他了\n\n\
什麼歐洲小王子\n什麼寶五120\n沒關係嘛\n都你們玩就好了嘛\n\n\
一直以來你們都嘛登GM帳\n我一個小小玩家\n非的怎麼幹得過歐的\n撒了幾百石丟水溝\n換來的只有綠方\n跟更多的綠方\n\n\
什麼彩光\n那種東西能吃嗎？\n什麼五星\n那種東西很強嗎？\n我就是一個小小沒見過世面的非洲人阿\n那種東西\n我稀罕嗎？",
    "https://media.discordapp.net/attachments/569812081965268992/1137384287428157521/11C3930E47E6DD1F0D5EC4D77F68B8DC.gif",
    "https://media.discordapp.net/attachments/968693698206519356/1143789019528974357/FB_IMG_1692752916136.jpg?width=375&height=375",
    "https://media.discordapp.net/attachments/968693698206519356/1143789019340210307/ZomboMeme_3116.jpg?width=576&height=662"
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
string gay[41] = {
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
    "https://cdn.discordapp.com/attachments/968693698206519356/1110106858477326376/348551627_234395815863993_2485886371128395134_n.png",
    "https://cdn.discordapp.com/attachments/968693698206519356/1127498944948219914/FB_IMG_1688620417978.jpg",
    "https://cdn.discordapp.com/attachments/966729542800658442/1127515998514323476/image.png",  //  25
    "https://media.discordapp.net/attachments/966729542800658442/1133091772856275157/FB_IMG_1690024293263.jpg?width=449&height=892",
    "https://cdn.discordapp.com/attachments/966729542800658442/1134105277424218212/image.png",
    "https://cdn.discordapp.com/attachments/966729542800658442/1134105544458764330/image.png",
    "https://imgur.com/33maruM",
    "https://cdn.discordapp.com/attachments/966729542800658442/1135474002090016839/image.png",  //  30
    "https://cdn.discordapp.com/attachments/966729542800658442/1135474025552957501/image.png",
    "https://cdn.discordapp.com/attachments/966729542800658442/1135474045425557544/image.png",
    "https://cdn.discordapp.com/attachments/966729542800658442/1135862352017887382/t0Z4horHE73AXH6k0jerhpOo4QjfruuBnURcsfVtGsYPXgkWmSlaf.jpg",
    "https://cdn.discordapp.com/attachments/966729542800658442/1136262065481330738/FB_IMG_1690976373803.jpg",
    "https://media.discordapp.net/attachments/966729542800658442/1138700764995403856/FB_IMG_1691557734693.jpg?width=605&height=547",  //  35
    "https://media.discordapp.net/attachments/966729542800658442/1138700765234475088/FB_IMG_1691557741111.jpg?width=875&height=875",
    "https://media.discordapp.net/attachments/966729542800658442/1138700765473554432/FB_IMG_1691557737218.jpg?width=1580&height=890",
    "https://media.discordapp.net/attachments/968693698206519356/1141940199845277776/FB_IMG_1692330118679.jpg?width=1176&height=662",
    "https://media.discordapp.net/attachments/968693698206519356/1141940200361173013/FB_IMG_1692330125590.jpg?width=400&height=400",
    "https://media.discordapp.net/attachments/968693698206519356/1141940200075952218/FB_IMG_1692330123098.jpg?width=863&height=662",  //  40
    "https://media.discordapp.net/attachments/968693698206519356/1141952623327592508/FB_IMG_1691732479628.jpg?width=617&height=662"
};
string wat[16]{
    "https://cdn.discordapp.com/attachments/966727921467260938/1107671890601988196/FB_IMG_1666237078979.jpg",
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
string ksexre[11] = {
    "我能理解你的疲憊。\n這段時間裡持久的戰鬥累積的壓力，令你躁動的生理需求超出了你所能忍耐的水平。",
    "奇怪，我理應不會被源石技藝帶來的任何錯覺干擾。",
    "......\n看來你的生命跡象與意識狀態尚不穩定。經過稍早的理學檢查，我已大致推斷出導致現狀的原因。",
    "看來你發作的時間比我預期的要早一些 -- 一如你在戰場上的決策那樣，總是出乎所有人的預料。",
    "Mo3ter，來幫個忙。",  //  5
    "這裡離最近的辦公室還有一段距離。\n希望你在此之前能保持清醒，羅德島戰術頭腦的醜態有我一個人看到就夠了。",
    "在為這片大地上的人們戰鬥之前，我們首先是活生生的人，而不是被符號化的意象。\n只有真正無血無淚的生物才沒有一己私慾、才不需要來自他人的幫助。",
    "感謝你一直以來的沉默，博士。\n但是沉默並不意味著要壓抑自己，不要忘記身後也有一齊為此努力的同伴。",
    "群星會衰老，這片大地則會一路向前不停不息。\n我，作為你漫長旅途的半個過客，你無須記住我也勿要了解我。\n你的思維是一片有限度的內存，有限度的思維理應思考更深刻艮古的問題。",
    "你將思考的情緒衝動加之於我，沒有必要，亦無意義。\n你有更重要的事情去做，而我微不足道。",  //  10
    "https://cdn.discordapp.com/attachments/966729542800658442/1134840733002629160/received_1043911593721873.jpg"
};
string cstre[11] = {
    "你看，チョコラ的下面都已經濕一片了喔？",
    "好的主人，就在這裡吧？",
    "チョコラ...只要一想到主人...身體都躁動了起來....",
    "好想要主人的大Ｏ棒...哈嘶哈嘶",
    "能跟主人做愛的チョコラ好幸福～",  //  5
    "啊......哈、呀！主人的手、好下流......嗯嗯......",
    "主人......看見了嗎？這就是チョコラ發情的模樣喔？",
    "喵......！不可以這麼突然啊、主人～",
    "主人會看到我發情的樣子......\n只...只能給主人你看到喔？",
    "主人，光看是不行的喔？",  //  10
    "才剛看了我淫蕩的臉就發情成這樣嗎？"
};
string cspre[5] = {
    "https://cdn.discordapp.com/attachments/1135513819565797457/1135513859474595951/image.png",
    "https://cdn.discordapp.com/attachments/1135513819565797457/1135514219597537301/image.png",
    "https://cdn.discordapp.com/attachments/1135513819565797457/1135514457477501018/image.png",
    "https://cdn.discordapp.com/attachments/1135513819565797457/1135515139743948861/image.png",
    "https://cdn.discordapp.com/attachments/1135513819565797457/1135515227094519928/image.png",  //  5
};
string mat[132][2] = {
{"連結", "https://docs.google.com/spreadsheets/d/1UudjnUd6xCg5dIJ8dLm2E9BT3p_qIm0biXk_J3eH0mg/edit?usp=sharing"},
{"表單連結", "https://docs.google.com/spreadsheets/d/1UudjnUd6xCg5dIJ8dLm2E9BT3p_qIm0biXk_J3eH0mg/edit?usp=sharing"},
{"功能", "輸入「素材 素材名稱」(暱稱及全名都可以)"},
{"功能介紹", "輸入「素材 素材名稱」(暱稱及全名都可以)"},
{"英雄之證", "1-3 海盜船 (同時缺虛影之塵就去 1-5 夏洛特)"},
{"黨證", "1-3 海盜船 (同時缺虛影之塵就去 1-5 夏洛特)"},
{"凶骨", "冬木 X-G (X-C也行，單件期望AP較低但要打較多場，X-D也是同理)"},
{"兇骨", "冬木 X-G (X-C也行，單件期望AP較低但要打較多場，X-D也是同理)"},
{"骨", "冬木 X-G (X-C也行，單件期望AP較低但要打較多場，X-D也是同理)"},
{"龍之牙", "1-5 德明 (1-7 埃里都也行，關卡消耗AP較高導致雖然掉率較高但單件期望理智也較高)"},
{"龍牙", "1-5 德明 (1-7 埃里都也行，關卡消耗AP較高導致雖然掉率較高但單件期望理智也較高)"},
{"虛影之塵", "1-5 夏洛特"},
{"塵", "1-5 夏洛特"},
{"灰塵", "1-5 夏洛特"},
{"塵土", "1-5 夏洛特"},
{"愚者之鎖", "1-6 死之荒野"},
{"鎖", "1-6 死之荒野"},
{"鎖鏈", "1-6 死之荒野"},
{"萬死的毒針", "1-7 蘆葦原"},
{"毒針", "1-7 蘆葦原"},
{"魔術髓液", "1.5-1 新宿站"},
{"髓液", "1.5-1 新宿站"},
{"宵泣之鐵樁", "1.5-4 絞刑丘陵"},
{"釘子", "1.5-4 絞刑丘陵"},
{"振盪火藥", "2-1 雅嘎·斯摩稜斯克"},
{"火藥", "2-1 雅嘎·斯摩稜斯克"},
{"赦免的小鐘", "2-6 霧之海岸"},
{"小鐘", "2-6 霧之海岸"},
{"黃昏の儀式劍", "2-6.5 シルミウム"},
{"儀式劍", "2-6.5 シルミウム"},
{"忘れじの灰", "2-6.5 ヨウィヌス砦(若同時缺儀式劍則可以刷 2-6.5 クサンテンの塔)"},
{"灰", "2-6.5 ヨウィヌス砦(若同時缺儀式劍則可以刷 2-6.5 クサンテンの塔)"},
{"黒曜鋭刃", "2-7 第四層 クラッシュポイント(若同時缺太陽皮可至 2-7 第三層 大平原)"},
{"黑曜銳刃", "2-7 第四層 クラッシュポイント(若同時缺太陽皮可至 2-7 第三層 大平原)"},
{"銳刃", "2-7 第四層 クラッシュポイント(若同時缺太陽皮可至 2-7 第三層 大平原)"},
{"狂気の残滓", "奏章I 虚数羅針内界ペーパームーン 構築部本部(若同時缺エーテル収光体可至 奏章I 虚数羅針内界ペーパームーン 修理部郊外)"},
{"章魚眼", "奏章I 虚数羅針内界ペーパームーン 構築部本部(若同時缺エーテル収光体可至 奏章I 虚数羅針内界ペーパームーン 修理部郊外)"},
{"世界樹之種", "1-7 廢都巴比倫"},
{"樹種", "1-7 廢都巴比倫"},
{"鬼魂提燈", "1-7 庫撒"},
{"提燈", "1-7 庫撒"},
{"八連雙晶", "1-5.2 桃源鄉"},
{"八連晶", "1-5.2 桃源鄉"},
{"雙晶", "1-5.2 桃源鄉"},
{"蛇之寶玉", "1-5.2 大地裂隙"},
{"蛇玉", "1-5.2 大地裂隙"},
{"寶玉", "1-5.2 大地裂隙"},
{"鳳凰羽毛", "1.5-4 公會堂"},
{"羽毛", "1.5-4 公會堂"},
{"無間齒輪", "1.5-1 槍身塔(同時缺弓職的秘、魔、輝石可以去 1-5 芝加哥)"},
{"齒輪", "1.5-1 槍身塔(同時缺弓職的秘、魔、輝石可以去 1-5 芝加哥)"},
{"禁斷書頁", "1.5-1 新宿二丁目"},
{"書頁", "1.5-1 新宿二丁目"},
{"人工生命體幼體", "1.5-4 維特利家"},
{"藥瓶", "1.5-4 維特利家"},
{"隕蹄鐵", "1-6 無之大地"},
{"馬蹄鐵", "1-6 無之大地"},
{"蹄鐵", "1-6 無之大地"},
{"大騎士勳章", "1-6 王城"},
{"勳章", "1-6 王城"},
{"追憶的貝殼", "1-7 觀測所"},
{"貝殼", "1-7 觀測所"},
{"枯淡勾玉", "1.5-3 城下町"},
{"勾玉", "1.5-3 城下町"},
{"玉", "1.5-3 城下町"},
{"永遠結冰", "2-1 雅嘎·莫斯科"},
{"冰", "2-1 雅嘎·莫斯科"},
{"巨人的指輪", "2-2 巨人的花園"},
{"指輪", "2-2 巨人的花園"},
{"戒指", "2-2 巨人的花園"},
{"極光之鋼", "2-2 雪與冰之城"},
{"極光鋼", "2-2 雪與冰之城"},
{"閑古鈴", "2-3 八門洞"},
{"禍罪之箭頭", "2-4 神之空岩遺跡(同時有缺金蛋可去 2-4 迪瓦爾)"},
{"箭頭", "2-4 神之空岩遺跡(同時有缺金蛋可去 2-4 迪瓦爾)"},
{"光銀之冠", "2-5.1 塔納托斯島(同時有缺煌星碎片可去 2-5.1 涅墨西斯島)"},
{"神脈靈子", "2-5.2 地下機構帶·外圍(同時缺悠久果實可去 2-5.2 星間都市南部)"},
{"虹色線球", "2-5.5 五條大橋(同時缺鬼炎鬼灯可去 2-5.5 三條三坊)"},
{"線球", "2-5.5 五條大橋(同時缺鬼炎鬼灯可去 2-5.5 三條三坊)"},
{"夢幻的鱗粉", "2-6 倫蒂尼恩(同時缺小鐘可去 2-6 牛津)"},
{"鱗粉", "2-6 倫蒂尼恩(同時缺小鐘可去 2-6 牛津)"},
{"太陽皮", "2-7 第五層 焼きモロコシ畑(若同時缺黒曜鋭刃可至 2-7 第三層 大平原)"},
{"皮", "2-7 第五層 焼きモロコシ畑(若同時缺黒曜鋭刃可至 2-7 第三層 大平原)"},
{"エーテル収光体", "奏章I 虚数羅針内界ペーパームーン 警防部本部(若同時缺狂気の残滓可至 奏章I 虚数羅針内界ペーパームーン 修理部郊外)"},
{"混沌之爪", "2-5.2 滑翔點(同時缺蛇之寶玉)、2-5.1 赫卡忒島(同時缺光銀之冠)、2-4 西之斷層(同時缺禍罪箭頭)、2-1 雅嘎·梁贊(同時缺永遠結冰)、1.5-2 地底平原(同時缺龍牙)、1.5-1 新宿四丁目(同時缺魔術髓液)"},
{"爪", "2-5.2 滑翔點(同時缺蛇之寶玉)、2-5.1 赫卡忒島(同時缺光銀之冠)、2-4 西之斷層(同時缺禍罪箭頭)、2-1 雅嘎·梁贊(同時缺永遠結冰)、1.5-2 地底平原(同時缺龍牙)、1.5-1 新宿四丁目(同時缺魔術髓液)"},
{"爪子", "2-5.2 滑翔點(同時缺蛇之寶玉)、2-5.1 赫卡忒島(同時缺光銀之冠)、2-4 西之斷層(同時缺禍罪箭頭)、2-1 雅嘎·梁贊(同時缺永遠結冰)、1.5-2 地底平原(同時缺龍牙)、1.5-1 新宿四丁目(同時缺魔術髓液)"},
{"蠻神心臟", "1.5-4 卡特家(同時缺鐵樁)、1.5-1 新宿御宛(同時缺魔術髓液)(因為掉率太低(掉率12%上下)，建議活動再收集)"},
{"心臟", "1.5-4 卡特家(同時缺鐵樁)、1.5-1 新宿御宛(同時缺魔術髓液)(因為掉率太低(掉率12%上下)，建議活動再收集)"},
{"龍之逆麟", "2-6 グロスター(同時缺小鐘和灰塵)1-7 尼普爾(同時缺萬死毒針)"},
{"龍之逆鱗", "2-6 グロスター(同時缺小鐘和灰塵)1-7 尼普爾(同時缺萬死毒針)"},
{"龍鱗", "2-6 グロスター(同時缺小鐘和灰塵)1-7 尼普爾(同時缺萬死毒針)"},
{"龍麟", "2-6 グロスター(同時缺小鐘和灰塵)1-7 尼普爾(同時缺萬死毒針)"},
{"逆鱗", "2-6 グロスター(同時缺小鐘和灰塵)1-7 尼普爾(同時缺萬死毒針)"},
{"逆麟", "2-6 グロスター(同時缺小鐘和灰塵)1-7 尼普爾(同時缺萬死毒針)"},
{"精靈根", "2-5.2 阿斯特蕾亞島(同時缺光銀之冠和灰塵)、2-2 被遺忘的神殿(同時缺極光之鋼)、1.5-1 塔頂樓(同時缺無間齒輪)、1-6 聖都市街(同時缺英雄之證和八連雙晶)(因為掉率太低(掉率10%上下)，建議活動再收集)"},
{"戰馬的幼角", "2-4 起始點(同時缺箭頭)、2-1 雅嘎·傑緬斯克(同時缺永遠結冰)、2-1 反叛軍的堡壘(同時缺火藥)、2-1 錨點(同時缺毒針)、1.5-2 野營地(同時缺羽毛和世界樹之種)(因為掉率太低(掉率15%上下)，建議活動再收集)"},
{"幼角", "2-4 起始點(同時缺箭頭)、2-1 雅嘎·傑緬斯克(同時缺永遠結冰)、2-1 反叛軍的堡壘(同時缺火藥)、2-1 錨點(同時缺毒針)、1.5-2 野營地(同時缺羽毛和世界樹之種)(因為掉率太低(掉率15%上下)，建議活動再收集)"},
{"角", "2-4 起始點(同時缺箭頭)、2-1 雅嘎·傑緬斯克(同時缺永遠結冰)、2-1 反叛軍的堡壘(同時缺火藥)、2-1 錨點(同時缺毒針)、1.5-2 野營地(同時缺羽毛和世界樹之種)(因為掉率太低(掉率15%上下)，建議活動再收集)"},
{"馬角", "2-4 起始點(同時缺箭頭)、2-1 雅嘎·傑緬斯克(同時缺永遠結冰)、2-1 反叛軍的堡壘(同時缺火藥)、2-1 錨點(同時缺毒針)、1.5-2 野營地(同時缺羽毛和世界樹之種)(因為掉率太低(掉率15%上下)，建議活動再收集)"},
{"血之淚石", "1.5-1 新宿二丁目(同時缺書頁)、1-5 亞歷山德里亞(同時缺英雄之證)(因為掉率太低(掉率15%上下)，建議活動再收集)"},
{"血石", "1.5-1 新宿二丁目(同時缺書頁)、1-5 亞歷山德里亞(同時缺英雄之證)(因為掉率太低(掉率15%上下)，建議活動再收集)"},
{"淚石", "1.5-1 新宿二丁目(同時缺書頁)、1-5 亞歷山德里亞(同時缺英雄之證)(因為掉率太低(掉率15%上下)，建議活動再收集)"},
{"黑獸脂", "2-4 隱遁窟(同時缺箭頭)、1.5-2 北部斷崖(同時缺鎖鏈)"},
{"膏", "2-4 隱遁窟(同時缺箭頭)、1.5-2 北部斷崖(同時缺鎖鏈)"},
{"獸膏", "2-4 隱遁窟(同時缺箭頭)、1.5-2 北部斷崖(同時缺鎖鏈)"},
{"黑膏", "2-4 隱遁窟(同時缺箭頭)、1.5-2 北部斷崖(同時缺鎖鏈)"},
{"封魔之燈", "2-4 東之花園(同時缺羽毛)、1.5-4 拘留所(同時缺龍牙)"},
{"燈", "2-4 東之花園(同時缺羽毛)、1.5-4 拘留所(同時缺龍牙)"},
{"智慧之聖甲蟲像", "1-6 大神殿(同時缺鎖鏈)、沙塵暴的沙漠(同時缺凶骨)(因為掉率太低(掉率10%上下)，建議活動再收集)"},
{"甲蟲", "1-6 大神殿(同時缺鎖鏈)、沙塵暴的沙漠(同時缺凶骨)(因為掉率太低(掉率10%上下)，建議活動再收集)"},
{"起源的胎毛", "2-2 通往盡頭之路(同時缺巨人指輪)、第67村落(同時缺極光鋼)、1-7 鮮血神殿(同時缺世界樹之種)"},
{"獸毛", "2-2 通往盡頭之路(同時缺巨人指輪)、第67村落(同時缺極光鋼)、1-7 鮮血神殿(同時缺世界樹之種)"},
{"胎毛", "2-2 通往盡頭之路(同時缺巨人指輪)、第67村落(同時缺極光鋼)、1-7 鮮血神殿(同時缺世界樹之種)"},
{"咒獸膽石", "1.5-3 荒川之原(同時缺勾玉和灰塵)、1-7 艾比夫山(同時缺世界樹之種)(因為掉率太低(掉率12%上下)，建議活動再收集)"},
{"膽石", "1.5-3 荒川之原(同時缺勾玉和灰塵)、1-7 艾比夫山(同時缺世界樹之種)(因為掉率太低(掉率12%上下)，建議活動再收集)"},
{"奇奇神酒", "2-5.2 大工房(同時缺神脈靈子和灰塵)、2-5.1 赫斯提雅島(同時缺光銀之冠)、2-3 冰冷窟(同時缺世界樹之種)、2-1 大溪谷之堡壘(缺灰塵和火藥)、1.5-3 土氣城(同時缺勾玉和灰塵)、1.5-2 龍宮城(同時缺英雄之證)(因為掉率太低(掉率10%上下)，建議活動再收集)"},
{"神酒", "2-5.2 大工房(同時缺神脈靈子和灰塵)、2-5.1 赫斯提雅島(同時缺光銀之冠)、2-3 冰冷窟(同時缺世界樹之種)、2-1 大溪谷之堡壘(缺灰塵和火藥)、1.5-3 土氣城(同時缺勾玉和灰塵)、1.5-2 龍宮城(同時缺英雄之證)(因為掉率太低(掉率10%上下)，建議活動再收集)"},
{"酒罐", "2-5.2 大工房(同時缺神脈靈子和灰塵)、2-5.1 赫斯提雅島(同時缺光銀之冠)、2-3 冰冷窟(同時缺世界樹之種)、2-1 大溪谷之堡壘(缺灰塵和火藥)、1.5-3 土氣城(同時缺勾玉和灰塵)、1.5-2 龍宮城(同時缺英雄之證)(因為掉率太低(掉率10%上下)，建議活動再收集)"},
{"曉光爐心", "2-5.2 破神同盟基地(同時缺神脈靈子)、星間都市西部(同時缺悠久果實)、2-5.1 忒提斯島(同時缺蛇之寶玉)、2-3 石泉峽(同時缺無間齒輪)、收容所(同時缺閑古鈴)"},
{"爐心", "2-5.2 破神同盟基地(同時缺神脈靈子)、星間都市西部(同時缺悠久果實)、2-5.1 忒提斯島(同時缺蛇之寶玉)、2-3 石泉峽(同時缺無間齒輪)、收容所(同時缺閑古鈴)"},
{"九十九鏡", "1.5-3 後山(戰戰競競)"},
{"鏡子", "1.5-3 後山(戰戰競競)"},
{"真理之卵", "2-5.5 稲荷神社(同時缺無間齒輪)、2-4 迪瓦爾(同時缺箭頭)、北之靈峰(同時缺灰塵和鎖鏈)、無窮之地(同時缺羽毛和灰塵)"},
{"金蛋", "2-5.5 稲荷神社(同時缺無間齒輪)、2-4 迪瓦爾(同時缺箭頭)、北之靈峰(同時缺灰塵和鎖鏈)、無窮之地(同時缺羽毛和灰塵)"},
{"煌星碎片", "2-5.2 機神迴廊(同時缺蛇之寶玉)、空中庭園(同時缺神脈靈子)、2-5.1 涅墨西斯島(同時缺光銀之冠)、啟航點(同時缺貝殼)"},
{"金平糖", "2-5.2 機神迴廊(同時缺蛇之寶玉)、空中庭園(同時缺神脈靈子)、2-5.1 涅墨西斯島(同時缺光銀之冠)、啟航點(同時缺貝殼)"},
{"星碎", "2-5.2 機神迴廊(同時缺蛇之寶玉)、空中庭園(同時缺神脈靈子)、2-5.1 涅墨西斯島(同時缺光銀之冠)、啟航點(同時缺貝殼)"},
{"悠久果實", "2-5.2 星間都市南部(同時缺神脈靈子)、星間都市東部(同時缺八連雙晶)、星間都市西部(同時缺曉光爐心)、祭壇街(同時缺蛇之寶玉)"},
{"果實", "2-5.2 星間都市南部(同時缺神脈靈子)、星間都市東部(同時缺八連雙晶)、星間都市西部(同時缺曉光爐心)、祭壇街(同時缺蛇之寶玉)"},
{"實", "2-5.2 星間都市南部(同時缺神脈靈子)、星間都市東部(同時缺八連雙晶)、星間都市西部(同時缺曉光爐心)、祭壇街(同時缺蛇之寶玉)"},
{"鬼炎鬼燈", "2-5.5 三條三坊(同時缺虹色線球)、大江山(同時缺凶骨)、朱雀門(同時缺勾玉)"},
};

string tkuse, txt, au, token[2], temp = { "" };
string jrtime = "https://www.eki-net.com/Personal/Top/Index\n\
https://www.jreast.co.jp/tickets/\n https://ekitan.com/timetable/railway/line/5000";
int sta[2] = { 1 };
vector<string> mwl;  //  mwl = majhong wating list

string pcrgacha(string times) {
    int integer = stoi(times);
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
    return ("一共抽到了：\n" + silver + "張銀卡 <:pcr1:1117798654548377641>\n"
        + golden + "張金卡 <:pcr2:1117798436427804754>\n" + rainbow + "張彩卡 <:pcr3:1117798715957194923>\n");
}
string fgogacha(string times) {
    int integer = stoi(times);
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
    return ("先說，我沒有保底\n\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n"
        + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n");
}
string arkgacha(string times) {
    int integer = stoi(times);
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
    return ("先說，我沒有保底\n\n一共抽到了：\n" + bronze + "張三星<:ark3:1107953947353808947>\n"
        + silver + "張四星<:ark4:1107953907377901579>\n" + golden + "張五星<:ark5:1107953865602637824>\n"
        + rainbow + "張六星<:ark6:1107953803057188905>\n");
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
        return ("一共抽了" + times + "抽\n一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n"
            + golden + "張金卡<:pcr2:1117798436427804754>\n1張彩卡<:pcr3:1117798715957194923>\n");
    else
        return ("so sad你保底了\n\n一共抽了200抽\n一共抽到了：\n" + silver + "張銀卡<:pcr1:1117798654548377641>\n"
            + golden + "張金卡<:pcr2:1117798436427804754>\n" + rainbow + "張彩卡<:pcr3:1117798715957194923>\n");
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
        return ("一共抽了" + times + "抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n"
            + golden + "張金卡<:fgo_K2:1107145363795746977>\n" + rainbow + "張彩卡<:fgo_K1:1107145268681519114>\n");
    else
        return ("so sad你保底了\n\n一共抽了330抽\n一共抽到了：\n" + silver + "張銀卡<:fgo_K3:1107145411724054532>\n"
            + golden + "張金卡<:fgo_K2:1107145363795746977>\n1張彩卡<:fgo_K1:1107145268681519114>\n");
}
string qreply() {
    if (tkuse == token[0])
        return "チョコラ不知道主人在說什麼欸";
        //return "現在登入的是チョコラ";
    else if (tkuse == token[1])
        return "再鬧\n我就叫M3捅爆你屁眼";
        //return "現在登入的是凱爾希";
    else
        return "哇程式竟然抓不到是哪一隻機器人登入\n可以趕快回報給開發者這個bug";
}

int main() {
    ifstream in;
    in.open("token.txt");
    in >> token[0] >> token[1]; //[0]為チョコラ [1]為女僕凱爾希
    tkuse = token[0];
    cluster bot(tkuse, i_default_intents | i_message_content);

    bot.on_log(utility::cout_logger());

    bot.on_slashcommand([](const slashcommand_t& event) {
        mt19937 mt(time(nullptr));

        if (event.command.get_command_name() == "cuttie")
            event.reply("https://cdn.discordapp.com/attachments/1091776372168474665/1121819763593711777/SPOILER_1565.jpg");
        else if (event.command.get_command_name() == "cattie")
            event.reply("https://cdn.discordapp.com/attachments/973282252186349588/1083963031077265528/IMG_6734.jpg");
        else if (event.command.get_command_name() == "bruh")
            event.reply("https://cdn.discordapp.com/attachments/933710044917288963/1092725740195295252/9k.png");
        else if (event.command.get_command_name() == "ark charaters")
            event.reply(arkcr[mt() % size(arkcr)]);
        }); //註冊斜線指令
    bot.on_ready([&bot](const ready_t& event) {

        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                slashcommand("cuttie", "it'll send pics", bot.me.id)
            );
            bot.global_command_create(
                slashcommand("cattie", "cute", bot.me.id)
            );
            bot.global_command_create(
                slashcommand("bruh", "bro", bot.me.id)
            );
            bot.global_command_create(
                slashcommand("ark charaters", "it'll send pics", bot.me.id)
            );
        }
        }); //使用斜線指令
    
    bot.on_message_create([&bot](const message_create_t& event) {
        string s = event.msg.content;
        au = to_string(event.msg.author.id);
        vector<string> v;
        while (v.size() < 10) {
            v.push_back(s.substr(0, s.find(" ")));
            s = s.substr(s.find(" ") + 1, s.length());

            if (s.find(" ") == 1) {
                v.push_back(s);
                break;
            }
        }
        //拆訊息

        if (au != "1121384376991752234" && au != "1092497000945160324" && size(event.msg.content) < 50 && sta[0] == 1){  //判斷是否進行比對
            //cout << "enter reading loop" << endl;
            mt19937 mt(time(nullptr));

            clock_t starttm = clock();
            time_t now = time(0);
            tm lctm{};
            localtime_s(&lctm, &now);

            s = event.msg.content;
            //bot.message_create(message(968693698206519356, "我讀到的你的訊息字串長為 " + to_string(size(s))));

            if (v[0] == "test") {
                if (au == "681076728465981450"){
                    /*for (int i = 0; i < size(arkcr); i++) {
                        bot.message_create(message(event.msg.channel_id, arkcr[i]));
                    }*/
                    bot.message_create(message(event.msg.channel_id, event.msg.author.get_mention(au)));
                }
                else
                    bot.message_create(message(event.msg.channel_id, "這指令是開發者專屬的，只有他可以用"));
            }
            else if (v[0] == "test1") {
                if (au == "681076728465981450")
                    bot.message_create(message(event.msg.channel_id, "已經" + to_string(lctm.tm_hour) + "點了非洲人還不睡喔"));
                else
                    bot.message_create(message(event.msg.channel_id, "這指令是開發者專屬的，只有他可以用"));
            }

            else if (s == "雀魂等待") {
                bot.message_create(message(event.msg.channel_id, "https://media.discordapp.net/attachments/988812288549093478/1099698505704022057/9F7E7973-93C7-4B07-9324-16D4BECC70A5.jpg"));
                for (auto it = mwl.begin(); it != mwl.end(); ++it) {
                    if (*it == au) {
                        bot.message_create(message(event.msg.channel_id, "你已在等待開局序列中"));
                        sta[1] = 0;
                        break;
                    }
                }
                if (sta[1] == 1) {
                    mwl.push_back(au);
                    bot.message_create(message(event.msg.channel_id, "等待區人數+1"));
                }
                sta[1] = 1;
            }
            else if (s == "等待人數") {
                bot.message_create(message(event.msg.channel_id, "目前有" + to_string(mwl.size()) + "人在等待開局"));
                for (auto it = mwl.begin(); it != mwl.end(); ++it) {
                    bot.message_create(message(event.msg.channel_id, event.msg.author.get_mention(*it)));
                }
            }
            else if (s == "退出等待") {
                for (int i = 0; i < mwl.size(); ++i) {
                    if (mwl[i] == au) {
                        mwl.erase(mwl.begin() + i);
                        bot.message_create(message(event.msg.channel_id, "已從等待區移除"));
                        sta[1] = 0;
                        break;
                    }
                }
                if (sta[1] == 1) {
                    bot.message_create(message(event.msg.channel_id, "你不在等待區"));
                }
                sta[1] = 1;
            }

            else if (s.find("休息") != -1 && au == "681076728465981450") {
                bot.message_create(message(event.msg.channel_id, "好我先去休息了").set_reference(event.msg.id));
                sta[0] = 0;
            }
            else if (s.find("椰子") != -1) {
                bot.message_create(message(event.msg.channel_id, "自己寫啊\n又不是不會打扣").set_reference(event.msg.id));
            }
            else if ((s.find("機") != -1 || s.find("bot") != -1) && (s.find("連結") != -1)) {
                bot.message_create(message(event.msg.channel_id, "https://github.com/kevinwei1029/dc-bot-withdpp").set_reference(event.msg.id));
            }
            else if (v[0] == "^n") {
                bot.message_create(message(event.msg.channel_id, "https://nhentai.net/g/" + v[1]).set_reference(event.msg.id));
            }
            else if (v[0] == "^p") {
                bot.message_create(message(event.msg.channel_id, "https://www.pixiv.net/artworks/" + v[1]).set_reference(event.msg.id));
            }
            else if (v[0] == "^jm") {
                bot.message_create(message(event.msg.channel_id, "https://jmcomic.me/photo/" + v[1]).set_reference(event.msg.id));
            }
            else if (s.find("歐") != -1 && s.find("歐貝爾") == -1 && s.find("歐虧") == -1) {
                bot.message_create(message(event.msg.channel_id, europe[mt() % size(europe)]));
            }
            else if (v[0] == "fga") {
                bot.message_create(message(event.msg.channel_id, "這是git本來的網站 https://github.com/Fate-Grand-Automata/FGA\n現在已經上架play商店了 https://play.google.com/store/apps/details?id=io.github.fate_grand_automata"));
            }
            else if (s.find("婆") != -1) {
                bot.message_create(message(event.msg.channel_id, "https://cdn.discordapp.com/attachments/966729542800658442/1092428172705931355/FB_IMG_1625811644856.jpg"));
            }
            else if (s.find("確實") != -1 || v[0] == "雀食") {
                bot.message_create(message(event.msg.channel_id, truee[mt() % size(truee)]));
            }
            else if (s.find("lao") != -1 || s.find("佬") != -1) {
                bot.message_create(message(event.msg.channel_id, dalao[mt() % size(dalao)]));
            }
            else if (s.find("kusa") != -1 || v[0] == "草" || s.find("笑死") != -1
                || (s.find("w") != -1 && s.find("ww") == -1 && s.find("ht") == -1)) {
                bot.message_create(message(event.msg.channel_id, kusa[mt() % size(kusa)]));
            }
            else if (s.find(u8"🏳️‍🌈") != -1 || s.find(u8"🈸") != -1
                || v[0] == "gay" || s.find("甲") != -1
                || v[0] == "給" || (s.find("是給") != -1 && s.find("倒是") == -1)
                || v[0] == "鈔給" || v[0] == "超給") {
                bot.message_create(message(event.msg.channel_id, gay[mt() % size(gay)]));
            }
            else if (s.find("fbi") != -1 || s.find("ㄌㄌㄎ") != -1) {
                bot.message_create(message(event.msg.channel_id, fbi[mt() % size(fbi)]));
            }
            else if (s.find("雀") != -1) {
                bot.message_create(message(event.msg.channel_id, "https://media.discordapp.net/attachments/988812288549093478/1099698505704022057/9F7E7973-93C7-4B07-9324-16D4BECC70A5.jpg"));
            }
            else if (v[0] == "圖") {
                bot.message_create(message(event.msg.channel_id, arkcr[mt() % size(arkcr)]));
            }
            else if (v[0] == "瓜" || v[0] == "吃瓜") {
                bot.message_create(message(event.msg.channel_id, "https://cdn.discordapp.com/attachments/503219154413682713/1107119476333350923/gcj_star230505.gif"));
            }
            else if (v[0] == "bonk" || v[0] == "不可以瑟瑟" || v[0] == "不可以色色") {
                bot.message_create(message(event.msg.channel_id, "<a:emoji_23:1008963509431840838>"));
            }
            else if ((s.find("JR") != -1 || s.find("jr") != -1) && s.find("時刻") != -1) {
                bot.message_create(message(event.msg.channel_id, jrtime));
            }
            else if (s.find("tsuna") != -1 || v[0] == "<:pte_lemon:986265384992772166>" || s.find("三小") != -1) {
                bot.message_create(message(event.msg.channel_id, wat[mt() % size(wat)]));
            }
            //抽卡相關程式碼
            else if (v[0] == "抽" || v[0] == "gacha" || v[0] == "抽卡") {
                while (tkuse == token[0]) {
                    bot.message_create(message(event.msg.channel_id, "好的主人幫您抽卡").set_reference(event.msg.id));
                    break;
                }
                if ((v[1] == "pcr" || v[1] == "公連") && (v[2].size() < 4))
                    bot.message_create(message(event.msg.channel_id, pcrgacha(v[2])));
                else if ((v[1] == "fgo" || v[1] == "居歐" || v[1] == "FGO") && (v[2].size() < 4))
                    bot.message_create(message(event.msg.channel_id, fgogacha(v[2])));
                else if ((v[1] == "ark" || v[1] == "方舟") && (v[2].size() < 4))
                    bot.message_create(message(event.msg.channel_id, arkgacha(v[2])));
                else
                    bot.message_create(message(event.msg.channel_id, qreply()));
            }
            else if (v[0] == "抽到有") {

                while (tkuse == token[0]) {
                    bot.message_create(message(event.msg.channel_id, "好的主人幫您抽卡").set_reference(event.msg.id));
                    break;
                }

                if (v[1] == "pcr" || v[1] == "公連")
                    bot.message_create(message(event.msg.channel_id, pcrget()));
                else if (v[1] == "fgo" || v[1] == "居歐")
                    bot.message_create(message(event.msg.channel_id, fgoget()));
                else
                    bot.message_create(message(event.msg.channel_id, qreply()));
            }
            else if (v[0] == "機率" || v[0] == "抽卡機率") {
                if (v[1] == "pcr" || v[1] == "公連")
                    txt = "★★★角色　3%\n★★角色　  18%\n★角色　　 79%";
                else if (v[1] == "fgo" || v[1] == "居歐" || v[1] == "FGO")
                    txt = "銀卡<:fgo_K3:1107145411724054532> 96%\n金卡<:fgo_K2:1107145363795746977> 3%\n彩卡<:fgo_K1:1107145268681519114> 1%";
                else if (v[1] == "ark" || v[1] == "方舟")
                    txt = "六星<:ark6:1107953803057188905> 2%\n五星<:ark5:1107953865602637824> 8%\n四星<:ark4:1107953907377901579> 30%\n三星<:ark3:1107953947353808947> 60%\n\n不要問我為什麼用狙信物，我絕對沒有對某隻六星狙有特別的偏好";
                else
                    bot.message_create(message(event.msg.channel_id, qreply()).set_reference(event.msg.id));

                bot.message_create(message(event.msg.channel_id, txt).set_reference(event.msg.id));
            }
            else if (v[0] == "亂數測試") {
                message msg(event.msg.channel_id, to_string(mt()));
                bot.message_create(msg.set_reference(event.msg.id));
            }
            else if (v[0] == "抽卡說明") {
                txt = "抽卡\n目前支援fgo、明日方舟與公主連結\nfgo與公主連結支援抽到有功能（有保底）\n\n抽卡功能使用公式\n抽(這裡用中文或半形英文打遊戲名稱) (這裡用半形數字打抽數)\n\n抽卡公式說明\n抽字為觸發功能必要、也可輸入gacha一詞代替\n三個區段間請用半形空格隔開\n遊戲名稱可打pcr、fgo、ark、公連、方舟、居歐\n最後請打抽數";
                message msg(event.msg.channel_id, txt);
                bot.message_create(msg.set_reference(event.msg.id));
            }
            //素材查詢程式碼
            else if (v[0] == "素材" || v[0] == "fgo素材") {
                bool find = FALSE;
                for (int i = 0; i < size(mat); i++) {
                    while (v[1] == mat[i][0]) {
                        message msg(event.msg.channel_id, mat[i][1]);
                        bot.message_create(msg.set_reference(event.msg.id));
                        find = TRUE;
                        break;
                    }
                }
                if (find == FALSE) {
                    message msg(event.msg.channel_id, qreply());
                    bot.message_create(msg.set_reference(event.msg.id));
                }
            }
            //想瑟瑟程式碼
            else if (tkuse == token[1] && s.find("老女人") != -1) {
                if (s.find("屁") != -1 || s.find("趴") != -1 || s.find("口") != -1 ||
                    s.find("脫") != -1 || s.find("露") != -1 || s.find("奶") != -1 ||
                    s.find("胸") != -1 || s.find("幹") != -1 || s.find("%") != -1) {
                    txt = ksexre[(mt() % size(ksexre))];
                }
                else
                    txt = "你說誰是老女人啊？";
                bot.message_create(message(event.msg.channel_id, txt));
            }
            else if (tkuse == token[0] && (s.find("貓") != -1 || s.find("チョコラ") != -1
                || s.find("chocola") != -1 || s.find("巧克力") != -1)) {
                if (s.find("屁") != -1 || s.find("趴") != -1 || s.find("口") != -1 ||
                    s.find("脫") != -1 || s.find("露") != -1 || s.find("奶") != -1 ||
                    s.find("胸") != -1 || s.find("幹") != -1 || s.find("%") != -1) {
                    bot.message_create(message(event.msg.channel_id, cstre[(mt() % size(cstre))]));
                    bot.message_create(message(event.msg.channel_id, cspre[(mt() % size(cspre))]));
                }
            }
            //embed程式碼
            else if (s == "!creator") {
                /* create the embed */
                dpp::embed embed = dpp::embed().
                    set_color(colors::sti_blue).
                    set_title("CREATOR").
                    set_url("https://github.com/kevinwei1029").
                    set_author("anime.photos.tw", "https://www.instagram.com/anime.photos.tw/", "https://cdn.discordapp.com/attachments/968693698206519356/1126715809511768176/1eaeade800d23f2c.png").
                    set_description("優木雪菜我婆！").
                    set_thumbnail("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                    add_field(
                        "感謝交大資工仔 @H1de_on_bruH 提供技術指導",
                        "點擊上面的連結、給辛苦的創作者一點流量跟感謝吧"
                    ).
                    add_field(
                        "這隻機器人他老杯很難過",
                        "燈燈退役了"
                    ).
                    add_field(
                        "歡迎逛逛這隻機器人的專案程式碼順便點個讚",
                        "https://github.com/kevinwei1029/dc-bot-withdpp"
                    ).
                    set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                    set_footer(dpp::embed_footer().set_text("我好喜歡小浠").set_icon("https://cdn.discordapp.com/attachments/981585424017420378/1126716388157964338/Mizuki_.png")).
                    set_timestamp(time(0));

                //reply with the created embed
                bot.message_create(message(event.msg.channel_id, embed).set_reference(event.msg.id));
            }
            else if (s == "!help" || s.find("!function") != -1) {
                /* create the embed */
                dpp::embed embed = dpp::embed().
                    set_color(colors::sti_blue).
                    set_title("FUNCTIONS").
                    set_url("https://github.com/kevinwei1029").
                    set_author("anime.photos.tw", "https://www.instagram.com/anime.photos.tw/", "https://cdn.discordapp.com/attachments/968693698206519356/1126715809511768176/1eaeade800d23f2c.png").
                    set_description("優木雪菜我婆！").
                    set_thumbnail("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                    add_field(
                        "可用斜線指令",
                        "new waifu \ncattie \nark charactors \nbruh \n"
                    ).
                    add_field(
                        "! 指令",
                        "help \ncreator \nbutton \n"
                    ).
                    add_field(
                        "^ 指令",
                        "支援n站、jm車號，以及pixiv圖片編號（8~9碼）"
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
                        "輸入\n素材 素材名稱(素材暱稱或全名都可以)\n"
                    ).
                    add_field(
                        "回應",
                        "對特定文字及表情符號\n"
                    ).
                    add_field(
                        "最後更新日期",
                        "2023/8/12"
                    ).
                    set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                    set_footer(dpp::embed_footer().set_text("我好喜歡小浠").set_icon("https://cdn.discordapp.com/attachments/981585424017420378/1126716388157964338/Mizuki_.png")).
                    set_timestamp(time(0));

                /* reply with the created embed */
                bot.message_create(message(event.msg.channel_id, embed).set_reference(event.msg.id));
            }
            //做不好的按鈕程式碼
            else if (s == "!button") {
                /* Create a message containing an action row, and a button within the action row. */
                bot.message_create(
                    message(event.msg.channel_id, "this text has buttons").add_component(
                        component().add_component(
                            component().set_label("Click me!").
                            set_type(cot_button).
                            set_emoji(u8"😄").
                            set_style(cos_danger).
                            set_id("測試中")
                        )
                    )
                );
            }
            else if (s == "!select") {
                /* Create a message containing an action row, and a select menu within the action row. */
                message m(event.msg.channel_id, "this text has a select menu");
                m.add_component(
                    component().add_component(
                        component().set_type(cot_selectmenu).
                        set_placeholder("Pick something").
                        add_select_option(select_option("label1", "value1", "description1").set_emoji(u8"😄")).
                        add_select_option(select_option("label2", "value2", "description2").set_emoji(u8"🙂")).
                        set_id("myselid")
                    )
                );
                bot.message_create(m);
            }
        }
        else if (au == "681076728465981450" && sta[0] == 0) {
            if (s.find("起來") != -1) {
                sta[0] = 1;
                bot.message_create(message(event.msg.channel_id, "好的，我回來了").set_reference(event.msg.id));
            }
            else if (s.find("狀態") != -1) {
                bot.message_create(message(event.msg.channel_id, "sta[0] = " + to_string(sta[0])).set_reference(event.msg.id));
            }
        }
    });

    //When a user clicks your button, the on_button_click event will fire, containing the custom_id you defined in your button.
    bot.on_button_click([&bot](const button_click_t & event) {
        // Button clicks are still interactions, and must be replied to in some form to prevent the "this interaction has failed" message from Discord to the user.
        event.reply("You clicked " + event.custom_id);
        });

    bot.start(st_wait);
    return 0;
}