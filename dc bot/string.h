#include <iostream>
using namespace std;

string tkuse, txt, au, token[2] = { "" };
string jrtime = "https://www.eki-net.com/Personal/Top/Index\n\
https://www.jreast.co.jp/tickets/\n\
https://ekitan.com/timetable/railway/line/5000";
string mjuse = "功能 => 中文指令 => 英文指令 => 中文辨識字元 => 英文辨識字元\n\n\
1. 加入等待序列 => 雀魂等待 => mjwaiting => 雀、待 => mjw\n\
2. 查看等待序列 => 等待人數 => mjlist => 人、待 => mjl\n\
3. 退出等待序列 => 退出等待 => mjquit => 退、待 => mjq\n\
4. 清空等待序列 => 清空等待 => mjclear => 空、待 => mjc\n\n\
辨識字元的意思是，只要有包含這些字詞就可以觸發功能......\n\
理論上啦\n\n\
要確認是否已加入等待序列需要看機器人有沒有給你回復\n\
傳圖不算回復，```等待區人數 + 1```才是有加入等待序列的回覆";

//所有字串陣列
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
string dalao[16] = {
    "https://imgur.com/hUQibPF",
    "https://imgur.com/XufO0dC",
    "https://imgur.com/cQzMQPO",
    "https://imgur.com/HrIbN5V",
    "https://imgur.com/4RXJHJX",  //  5
    "https://imgur.com/VsY7vaX",
    "https://imgur.com/mVgZiOm",
    "https://imgur.com/hCVPjxj",
    "https://imgur.com/lPBlrhY",
    "https://imgur.com/AnadWlD",  //  10
    "https://imgur.com/tAXzWU0",
    "https://imgur.com/LI8F2rz",
    "https://imgur.com/9zeOJP1",
    "https://imgur.com/A9V2sfw",
    "https://imgur.com/xMloJk1",  //  15
    "https://imgur.com/OGLv1FV",
};
string europe[9] = {
    "我沒差啊\n你們都這樣\n我習慣了阿\n\n\
你們在曬的時候有考慮過我的感受嗎？\n沒有阿\n從以前到現在一直以來都沒有阿\n\n\
阿我就是非洲阿\n什麼幾抽寶幾\n我現在都不在意了\n就連那個未持有\n我現在都已經懶得理他了\n\n\
什麼歐洲小王子\n什麼寶五120\n沒關係嘛\n都你們玩就好了嘛\n\n\
一直以來你們都嘛登GM帳\n我一個小小玩家\n非的怎麼幹得過歐的\n撒了幾百石丟水溝\n換來的只有綠方\n跟更多的綠方\n\n\
什麼彩光\n那種東西能吃嗎？\n什麼五星\n那種東西很強嗎？\n我就是一個小小沒見過世面的非洲人阿\n那種東西\n我稀罕嗎？",
    "https://imgur.com/g0m55zX",
    "https://imgur.com/zAiXdKx",
    "https://imgur.com/RIAHybO",
    "https://imgur.com/DYa9pJG",  //  5
    "https://imgur.com/kwGyqFY",
    "https://imgur.com/C3NM0u6",
    "https://imgur.com/Ab4b6I0",
    "https://imgur.com/b8R5npH"
};
string fbi[14] = {
    "https://imgur.com/8G9kPNg",
    "https://imgur.com/zUGMmNw",
    "https://imgur.com/B2jRZjU",
    "https://imgur.com/2tmILhE",
    "https://imgur.com/zZVcqhY",  //  5
    "https://imgur.com/elDMlBV",
    "https://imgur.com/zWE5qHk",
    "https://imgur.com/qHjPP3x",
    "https://imgur.com/bqTAD1D",
    "https://imgur.com/rI4wsTj",  //  10
    "https://imgur.com/J9Lxbfn",
    "https://imgur.com/id0Li6k",
    "https://imgur.com/UQKmyNe",
    "https://imgur.com/q8EEITg",
};
string kusa[16] = {
    "https://imgur.com/7t35JNT",
    "https://imgur.com/TxP9fcI",
    "https://imgur.com/i7r8tKl",
    "https://imgur.com/DApX2Nu",
    "https://imgur.com/ThxxMl1",  //  5
    "https://imgur.com/HamEFgu",
    "https://imgur.com/uxBRuX6",
    "https://imgur.com/olT86SJ",
    "https://imgur.com/c4ZpeHP",
    "https://imgur.com/WelweuA",  //  10
    "https://imgur.com/A8Npz1A",
    "https://imgur.com/rUGDSKW",
    "https://imgur.com/nAaTS18",
    "https://imgur.com/mpnIp9x",
    "https://imgur.com/yP0kmFE",  //  15
    "https://imgur.com/BHyj0zZ",
};
string truee[8] = {
    "https://imgur.com/GGvgJiZ",
    "https://imgur.com/N6sLTa2",
    "https://imgur.com/5iGBT7f",
    "https://imgur.com/QIWd82j",
    "https://imgur.com/mjRd41N",  //  5
    "https://imgur.com/0zJZ587",
    "https://imgur.com/Clv4BdA",
    "https://imgur.com/IBkAlTX",
};
string gay[42] = {
    "https://imgur.com/33maruM",
    "https://imgur.com/zk5mVtC",
    "https://imgur.com/BhvOl22",
    "https://imgur.com/eAwtpeP",
    "https://imgur.com/FtXy0BV",  //  5
    "https://imgur.com/TNRlai2",
    "https://imgur.com/d6XWJEb",
    "https://imgur.com/eMrFNNs",
    "https://imgur.com/RihzeDj",
    "https://imgur.com/91Moo77",  //  10
    "https://imgur.com/IBy5GQS",
    "https://imgur.com/x5ZbTQu",
    "https://imgur.com/gAAN5JK",
    "https://imgur.com/s3P52bM",
    "https://imgur.com/EELYt3i",  //  15
    "https://imgur.com/CLo4pS3",
    "https://imgur.com/S9MxnX0",
    "https://imgur.com/NDuBaGv",
    "https://imgur.com/t5nRYnz",
    "https://imgur.com/UWJp5Bv",  //  20
    "https://imgur.com/eDZZs2D",
    "https://imgur.com/PfvvIuD",
    "https://imgur.com/RYjNT0S",
    "https://imgur.com/mHelSCB",
    "https://imgur.com/liMjWdN",  //  25
    "https://imgur.com/PSr7nat",
    "https://imgur.com/BVxuAeo",
    "https://imgur.com/OR1GU8j",
    "https://imgur.com/ol6jUnn",
    "https://imgur.com/uExhvdM",  //  30
    "https://imgur.com/sdgezFu",
    "https://imgur.com/A3yHbeX",
    "https://imgur.com/8paik7Y",
    "https://imgur.com/rX545TH",
    "https://imgur.com/6YrEQnp",  //  35
    "https://imgur.com/PAXpiRe",
    "https://imgur.com/Bwt1ikK",
    "https://imgur.com/8aZ4vms",
    "https://imgur.com/ULeOPt9",
    "https://imgur.com/CXuYUtR",  //  40
    "https://imgur.com/jjZtKBN",
    "https://imgur.com/Ly8s2YZ",
};
string wat[20]{
    "https://imgur.com/Uz1ZWqo",
    "https://imgur.com/OUvENhb",
    "https://imgur.com/WRdAmE3",
    "https://imgur.com/Goq7oSm",
    "https://imgur.com/04p2oat",  //  5
    "https://imgur.com/SgninOv",
    "https://imgur.com/j0Am8wF",
    "https://imgur.com/4yzSiaV",
    "https://imgur.com/aDUbYds",
    "https://imgur.com/2qvoo4I",  //  10
    "https://imgur.com/nGGcyoL",
    "https://imgur.com/nbFeEGZ",
    "https://imgur.com/nbFeEGZ",
    "https://imgur.com/WbC0tOZ",
    "https://imgur.com/NlhCcKX",  //  15
    "https://imgur.com/EMuqioj",
    "https://imgur.com/13bjl4R",
    "https://imgur.com/fegAxh0",
    "https://imgur.com/9FzSvH3",
    "https://imgur.com/vyMNDbT",  //  20
};
string ksexre[11] = {
    "我能理解你的疲憊。\n這段時間裡持久的戰鬥累積的壓力，令你躁動的生理需求超出了你所能忍耐的水平。",
    "奇怪，我理應不會被源石技藝帶來的任何錯覺干擾。",
    "......\n看來你的生命跡象與意識狀態尚不穩定。經過稍早的理學檢查，我已大致推斷出導致現狀的原因。",
    "看來你發作的時間比我預期的要早一些 -- 一如你在戰場上的決策那樣，總是出乎所有人的預料。",
    "Mo3ter，來幫個忙。",  //  5
    "這裡離最近的辦公室還有一段距離。\n\
希望你在此之前能保持清醒，羅德島戰術頭腦的醜態有我一個人看到就夠了。",
    "在為這片大地上的人們戰鬥之前，我們首先是活生生的人，而不是被符號化的意象。\n\
只有真正無血無淚的生物才沒有一己私慾、才不需要來自他人的幫助。",
    "感謝你一直以來的沉默，博士。\n但是沉默並不意味著要壓抑自己，不要忘記身後也有一齊為此努力的同伴。",
    "群星會衰老，這片大地則會一路向前不停不息。\n\
我，作為你漫長旅途的半個過客，你無須記住我也勿要了解我。\n\
你的思維是一片有限度的內存，有限度的思維理應思考更深刻艮古的問題。",
    "你將思考的情緒衝動加之於我，沒有必要，亦無意義。\n\
你有更重要的事情去做，而我微不足道。",  //  10
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
string genshin[5] = {
    "https://cdn.discordapp.com/attachments/968693698206519356/1144973309633630279/ab8164c0-7a7c-11ec-bfef-21d6e5102eb6.webp.jpg",
    "",
    "",
    "",
    "",  //  5
};
string nazi[9] = {
    "https://imgur.com/11XKQcu",
    "https://imgur.com/PEbwSv0",
    "https://imgur.com/R8j3yCx",
    "https://imgur.com/YE3n1EU",
    "https://imgur.com/KSnFKDW",  //  5
    "https://imgur.com/lhVDMZP",
    "https://imgur.com/gNjMQ21",
    "https://imgur.com/4jwzdqd",
    "https://imgur.com/50vT4IU",
};
string boobs[10] = {
    "https://imgur.com/vZODCIO",
    "https://imgur.com/98Vakee",
    "https://imgur.com/Vf5WBPx",
    "https://imgur.com/Jno0naL",
    "https://imgur.com/tzSBzSb",  //  5
    "https://imgur.com/EBhpL7L",
    "https://imgur.com/NyHljSu",
    "https://imgur.com/0XzWnRg",
    "https://imgur.com/O9Lqwkc",
    "https://imgur.com/igTwwD1",  //  10
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
//只是看行數自爽用
