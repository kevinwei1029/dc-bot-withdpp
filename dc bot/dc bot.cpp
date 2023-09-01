//#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <dpp/dpp.h>
#include <random>
#include <fstream>
#include <ctime>
#include "functions.h"  //存放陣列字串及自訂函式
#include "string.h"

using namespace std;
using namespace dpp;
using json = nlohmann::json;

int sta[2] = { 1 };
vector<string> mwl;  //  mwl = majhong wating list

//有用到tkuse搬不過去
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

            else if ((s.find("雀") != -1 && s.find("待") != -1) || s.find("mjw") != -1) {
                for (auto it = mwl.begin(); it != mwl.end(); ++it) {
                    if (*it == au) {
                        bot.message_create(message(event.msg.channel_id, "你已在等待開局序列中").set_reference(event.msg.id));
                        sta[1] = 0;
                        break;
                    }
                }
                if (sta[1] == 1) {
                    mwl.push_back(au);
                    bot.message_create(message(event.msg.channel_id, "等待區人數+1").set_reference(event.msg.id));
                    //bot.message_create(message(event.msg.channel_id, "https://media.discordapp.net/attachments/988812288549093478/1099698505704022057/9F7E7973-93C7-4B07-9324-16D4BECC70A5.jpg"));
                }
                bot.message_create(message(event.msg.channel_id, mjnre(mwl.size())));
                sta[1] = 1;
            }
            else if ((s.find("人") != -1 && s.find("待") != -1) || s.find("mjl") != -1) {
                bot.message_create(message(event.msg.channel_id, mjnre(mwl.size())).set_reference(event.msg.id));
                for (auto it = mwl.begin(); it != mwl.end(); ++it) {
                    bot.message_create(message(event.msg.channel_id, event.msg.author.get_mention(*it)));
                }
            }
            else if ((s.find("退") != -1 && s.find("待") != -1) || s.find("mjq") != -1) {
                for (auto it = mwl.begin(); it != mwl.end(); ++it) {
                    if (*it == au) {
                        mwl.erase(it);
                        bot.message_create(message(event.msg.channel_id, "已從等待區移除").set_reference(event.msg.id));
                        sta[1] = 0;
                        break;
                    }
                }
                if (sta[1] == 1) {
                    bot.message_create(message(event.msg.channel_id, "你不在等待區").set_reference(event.msg.id));
                }
                sta[1] = 1;
            }
            else if ((s.find("空") != -1 && s.find("待") != -1) || s.find("mjc") != -1) {
                mwl.clear();
                bot.message_create(message(event.msg.channel_id, "等待序列已清空").set_reference(event.msg.id));
            }
            else if ((s.find("功") != -1 && s.find("待") != -1) || s.find("mjf") != -1) {
                mwl.clear();
                bot.message_create(message(event.msg.channel_id, mjuse).set_reference(event.msg.id));
            }

            else if (s.find("休息") != -1 && au == "681076728465981450") {
                bot.message_create(message(event.msg.channel_id, "好我先去休息了").set_reference(event.msg.id));
                sta[0] = 0;
            }
            else if (s.find("椰子") != -1) {
                bot.message_create(message(event.msg.channel_id, "自己寫啊\n又不是不會打扣").set_reference(event.msg.id));
            }
            else if (s.find("機") != -1 && (s.find("連結") != -1)) {
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
                bot.message_create(message(event.msg.channel_id, "這是git本來的網站 https://github.com/Fate-Grand-Automata/FGA\n\
                    現在已經上架play商店了 https://play.google.com/store/apps/details?id=io.github.fate_grand_automata"));
            }
            else if (s.find("婆") != -1) {
                bot.message_create(message(event.msg.channel_id, "https://cdn.discordapp.com/attachments/966729542800658442/1092428172705931355/FB_IMG_1625811644856.jpg"));
            }
            else if (s.find("確實") != -1 || v[0] == "雀食") {
                bot.message_create(message(event.msg.channel_id, truee[mt() % size(truee)]));
            }
            else if ((s.find("猶") != -1 && s.find("猶豫") == -1) || v[0] == "德意") {
                bot.message_create(message(event.msg.channel_id, nazi[mt() % size(nazi)]));
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
                || v[0] == "給" || (s.find("是給") != -1 && s.find("倒是") == -1) || v[0] == "超給") {
                bot.message_create(message(event.msg.channel_id, gay[mt() % size(gay)]));
            }
            else if (s.find("fbi") != -1 || s.find("ㄌㄌㄎ") != -1) {
                bot.message_create(message(event.msg.channel_id, fbi[mt() % size(fbi)]));
            }
            else if (s.find("哇草原") != -1) {
                bot.message_create(message(event.msg.channel_id, genshin[0]));
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
                        "歡迎逛逛這隻機器人的專案程式碼順便點個讚",
                        "https://github.com/kevinwei1029/dc-bot-withdpp"
                    ).
                    add_field(
                        "Bnag Dream It's MyGO!!!!!超好看",
                        "Bnag Dream It's MyGO!!!!!超好看\n\
                         Bnag Dream It's MyGO!!!!!超好看"
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
                        "new waifu \ncattie \nark charactors \nbruh"
                    ).
                    add_field(
                        "! 指令",
                        "help \ncreator \nbutton"
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
                        "抽 (遊戲名稱、中文或半形英文) (抽數、半形數字)"
                    ).
                    add_field(
                        "抽卡公式說明",
                        "抽字為觸發功能必要、也可輸入gacha代替\n\
                         三個區段間請用半形空格隔開\n\
                         遊戲名稱可用pcr、ark、fgo、公連、方舟、居歐\n\
                         最後打抽數"
                    ).
                    add_field(
                        "fgo素材掉落關卡查詢",
                        "輸入\n素材 素材名稱(素材暱稱或全名都可以)"
                    ).
                    add_field(
                        "回應",
                        "對特定文字及表情符號"
                    ).
                    add_field(
                        "雀魂待機序列",
                        "單獨發「雀魂等待」\n機器人會把你各位加到一個序列中\n\
                         單獨發「等待人數」\n機器人會告訴你現在有多少人在等待開局\n\
                         單獨發「退出等待」\n機器人會把你移出等待序列"
                    ).
                    add_field(
                        "最後更新日期",
                        "2023/8/25"
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