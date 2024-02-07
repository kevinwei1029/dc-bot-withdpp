//#define _CRT_SECURE_NO_DEPRECATE
#include "functions.h"  //存放自訂函式
#define tid = 968693698206519356
#define utc_area 8

Gacha gacha;
Acceed senbai;

int main() {
    ifstream tkin;
    tkin.open("token.txt");
    tkin >> token[0] >> token[1]; //  [0]為ショコラ [1]為女僕凱爾希
    tkin.close();
    tkuse = token[0];  //  [1]已被踢出
    cluster bot(tkuse, i_default_intents | i_message_content);

    bot.on_log(utility::cout_logger());

    bot.on_user_context_menu([](const dpp::user_context_menu_t& event) {
        // check if the context menu name is High Five
        if (event.command.get_command_name() == "high five") {
            dpp::user user = event.get_user(); // the user who the command has been issued on
            dpp::user author = event.command.get_issuing_user(); // the user who clicked on the context menu
            event.reply(author.get_mention() + " slapped " + user.get_mention());
        }
        else if (event.command.get_command_name() == "cuttie")
            event.reply("https://imgur.com/aVtILpp");
        else if (event.command.get_command_name() == "cattie")
            event.reply("https://imgur.com/aVtILpp");
        else if (event.command.get_command_name() == "bruh")
            event.reply("https://imgur.com/ucwb6HY");
        else if (event.command.get_command_name() == "ark charaters")
            event.reply(arkcr[mt() % size(arkcr)]);
        });  //  使用斜線指令
    bot.on_ready([&bot](const ready_t& event) {
        if (run_once<struct register_bot_commands>()) {

            bot.set_presence(presence(presence_status::ps_online, activity_type::at_listening, "來自 " + to_string(get_guild_cache()->count()) + " 個伺服器的指令"));
            bot.start_timer([&bot](const timer& timer) {
                bot.set_presence(presence(presence_status::ps_online, activity_type::at_listening, "來自 " + to_string(get_guild_cache()->count()) + " 個伺服器的指令"));
            }, 60);  // Create a timer that runs every 60 seconds, that sets the status

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
        }); //setup & 註冊斜線指令

    bot.on_message_create([&bot](const message_create_t& event) {
        s = event.msg.content;
        au = to_string(event.msg.author.id);
        v.clear();
        while (v.size() < 10) {
            v.push_back(s.substr(0, s.find(" ")));
            s = s.substr(s.find(" ") + 1);
        }
        v.push_back(s);
        s = event.msg.content;
        //拆訊息

        localtime_s(&local, &event.msg.sent);
        local.tm_hour += utc_area;
        local.tm_hour = local.tm_hour % 24;

        react_collector* r = nullptr;

        if (au == "1092497000945160324") {
            ofstream jsonfile("mesdata.json");
            //json mesdata = event.msg.build_json(true, true);
            jsonfile << event.msg.build_json(true, true) << endl;
            jsonfile.close();
            /*
            Decodejson *del = new Decodejson;
            Sleep(1000);
            bot.message_delete(del->getms(), del->getch());
            bot.message_create(message(event.msg.channel_id, "已自刪回復"));
            delete del;*/
        }
        else if (size(event.msg.content) < 150 && sta[0] == 1) {
            //bot.message_create(message(tid, "我讀到的你的訊息字串長為 " + to_string(size(s))));
            bot.message_create(message(event.msg.channel_id, "我讀到你的訊息為" + event.msg.content + "\ns = " + s));

            //有限本人用的程式碼
            if (v[0] == "test") {
                if (au == "681076728465981450"){
                    bot.message_create(message(event.msg.channel_id, event.msg.author.get_mention(au)));
                    //bot.message_create(message(memech[0], to_string(event.msg.guild_id)));
                }
                else
                    bot.message_create(message(event.msg.channel_id, "這指令是開發者專屬的，只有他可以用"));
            }
            else if (v[0] == "test1") {
                if (au == "681076728465981450")
                    bot.message_create(message(event.msg.channel_id, "已經" + to_string(local.tm_hour) + "點了，主人要早點去睡覺喔！"));
                else
                    bot.message_create(message(event.msg.channel_id, "這指令是開發者專屬的，只有他可以用"));
            }
            else if (s == "關機" || s == "sd") {
                if (au == "681076728465981450") {
                    bot.message_create(message(event.msg.channel_id, "機器人將於三秒後關機"));
                    Sleep(3000);
                    exit(0);
                }
                else
                    bot.message_create(message(event.msg.channel_id, "這指令是開發者專屬的，只有他可以用"));
            }

            //cmd程式碼
            else if (v[0] == "cmd") {
                if (au == "681076728465981450") {
                    cmd(s.substr(4));
                    //txt = CreateProcess(s.c_str(), SW_SHOWNORMAL);
                    //bot.message_create(message(event.msg.channel_id, txt));
                }
                else {
                    cc.push_back( s.substr(4) );
                    bot.message_create(message(event.msg.channel_id, "Your cmd command is waiting for apporval."));
                }
                    //bot.message_create(message(event.msg.channel_id, "這指令是開發者專屬的，只有他可以用"));
            }
            else if ((v[0] == "granted") || (v[0] == "deny") && cc[0] != "") {
                if (v[0] == "granted") {
                    bot.message_create(message(event.msg.channel_id, "Guest cmd command is been conducting : \n" + cc[0]));
                    cmd(cc[0]);
                    bot.message_create(message(event.msg.channel_id, txt));
                    cc.erase(cc.begin());
                }
                else if (v[0] == "deny") {
                    bot.message_create(message(event.msg.channel_id, "Guest cmd command is not allowed to conduct"));
                    cc.erase(cc.begin());
                }

                if (cc.size() != 0) {
                    bot.message_create(message(968693698206519356, "There still have some guest cmd command waiting for your approval :\n"));
                    for (auto it = cc.begin(); it != cc.end(); it++) {
                        bot.message_create(message(968693698206519356, *it + "\n"));
                    }
                }
            }

            //用到json程式碼
            else if (s.find("刪我") != -1 || s == "delete me") {
                bot.message_delete(event.msg.id, event.msg.channel_id);
                /*
                // 獲取收到的訊息 
                dpp::message dmsg;
                dmsg.channel_id = event.msg.channel_id; // 替換為要發送訊息的頻道 ID
                dmsg.content = "Hello from Discord++ (DPP)!\nThis is a delete test.";
                //Deletemes* ptr = new Deletemes(dmsg);
                bot.message_create(dmsg);
                Sleep(5000);
                //co_await(bot.message_create(dmsg));
                
                dpp::message delete_msg = dmsg;
                // 刪除訊息
                bot.message_delete(delete_msg.id, delete_msg.channel_id);
                bot.message_create(message(event.msg.channel_id, "已經照您的要求刪掉了\nchannel id : " + to_string(delete_msg.channel_id)
                    + "\nmsg id : " + to_string(delete_msg.id)));*/
            }
            else if (s.find("自刪") != -1) {
                Decodejson* del = new Decodejson;
                //cerr << "message id = " << del->getms() << "\nchannel id = " << del->getch() << "\ncontent = " << del->getcont();
                bot.message_delete(del->getms(), del->getch());
                bot.message_create(message(event.msg.channel_id, "已自刪"));
                delete del;
            }
            else if (s == "ed") {
                //bot.message_create(message(event.msg.channel_id, "edit test"));
                dpp::message update_msg = event.msg;
                update_msg.content = "edited";
                Decodejson* lastmes = new Decodejson;
                update_msg.id = lastmes->getms();
                delete lastmes;
                
                bot.message_edit(update_msg, [&](const dpp::confirmation_callback_t& callback) {
                    // 檢查編輯是否成功
                    if (callback.is_error()) {
                        // 編輯失敗 
                        bot.message_create(message(update_msg.channel_id, "edit failed"));
                    }
                    else {
                        // 編輯成功 
                        bot.message_create(message(update_msg.channel_id, "edit done"));
                    }
                });
            }
            else if (s.find("json") != -1) {
                json jsonmes = event.msg.build_json(true, true);
                string jsmesdump = jsonmes.dump();
                bot.message_create(message(event.msg.channel_id, jsmesdump));

                ofstream jsonfile("usermesdata.json");
                json mesdata = event.msg.build_json(true, true);
                jsonfile << setw(4) << mesdata << endl;
                jsonfile.close();
            }
            else if (s == "刪他") {
                Decodejson* ref = new Decodejson(event.msg.build_json(true, true));
                if (ref->getrefms().empty() || ref->getrefch().empty()) {
                    bot.message_create(message(event.msg.channel_id, "你沒有回覆訊息喔？"));
                }
                else {
                    bot.message_delete(ref->getrefms(), ref->getrefch());
                }
                delete ref;
            }
            
            //其他的程式碼
            else if (s == "!rest") {
                bot.message_create(
                    message(event.msg.channel_id, "主人要讓巧克力休息多久呢？")
                    .add_component(
                        component().add_component(
                            component().set_label("30分鐘").
                            set_type(cot_button).
                            set_style(cos_primary).
                            set_id("rest30m")
                        )
                    )
                    .add_component(
                        component().add_component(
                            component().set_label("1小時").
                            set_type(cot_button).
                            set_style(cos_secondary).
                            set_id("rest1h")
                        )
                    )
                    .add_component(
                        component().add_component(
                            component().set_label("直到再次喚醒").
                            set_type(cot_button).
                            set_style(cos_danger).
                            set_id("resttc")  //  resttc = rest till call
                        )
                    )
                );
            }
            else if (s == "董") {
                bot.message_create(message(event.msg.channel_id, "https://imgur.com/bLRrdO4"));
            }
            else if (s.find("機器人") != -1 && (s.find("連結") != -1)) {
                bot.message_create(message(event.msg.channel_id, "https://github.com/kevinwei1029/dc-bot-withdpp").set_reference(event.msg.id));
            }
            else if (s.find("婆") != -1) {
                bot.message_create(message(event.msg.channel_id, "https://imgur.com/NzDj4b3"));
            }
            else if (s.find("瓜") != -1) {
                bot.message_create(message(event.msg.channel_id, "https://imgur.com/E4EWNsw"));
            }
            else if ((s.find("JR") != -1 || s.find("jr") != -1) && s.find("時刻") != -1) {
                bot.message_create(message(event.msg.channel_id, jrtime));
            }
            /*else if (v[0].find("轉") != -1) {
                if (v[1] == "梗圖") {
                    for (int i = 0; i < size(memech); i++) {
                        while (memech[i] != event.msg.channel_id) {
                            bot.message_create(message(memech[i], v[2]));
                            break;
                        }
                    }
                    bot.message_create(message(event.msg.channel_id, "已經轉傳到其他頻道了！"));
                }
            }*/
            else if (s.find("檸檬") != -1 && to_string(event.msg.channel_id) == "966724745708052520") {
                bot.message_create(message(966724745708052520, "https://imgur.com/0T1ZxAF"));
            }
            else if (s.find("聖誕快樂") != -1) {
                bot.message_create(message(event.msg.channel_id, "https://imgur.com/JYyKXU2"));
            }
            else if (event.msg.mention_everyone) {
                bot.message_create(message(event.msg.channel_id, "https://imgur.com/dBzNTzQ"));
            }
            else if (v[0] == "論證") {
                bot.message_create(message(event.msg.channel_id, senbai.rep(stoi(v[1]))));
            }

            else if (event.msg.content == "c!" && r == nullptr) {
                // Create a new reaction collector to collect reactions
                bot.message_create(message(event.msg.channel_id, "enter if loop"));
                r = new react_collector(&bot, event.msg.id);
            }

            //發車的程式碼
            else if (v[0] == "^n") {
                bot.message_create(message(event.msg.channel_id, "https://nhentai.net/g/" + v[1]).set_reference(event.msg.id));
            }
            else if (v[0] == "^p") {
                bot.message_create(message(event.msg.channel_id, "https://www.pixiv.net/artworks/" + v[1]).set_reference(event.msg.id));
            }
            else if (v[0] == "^jm") {
                bot.message_create(message(event.msg.channel_id, "https://jmcomic.me/photo/" + v[1]).set_reference(event.msg.id));
            }
            else if (v[0] == "^w") {
                bot.message_create(message(event.msg.channel_id, "https://www.wnacg.com/photos-index-aid-" + v[1] + ".html").set_reference(event.msg.id));
            }

            //用隔壁陣列發圖的程式碼
            else if (v[0] == "圖") {
                bot.message_create(message(event.msg.channel_id, arkcr[mt() % size(arkcr)]));
            }
            else if (s.find("哇草原") != -1) {
                bot.message_create(message(event.msg.channel_id, genshin[mt() % size(genshin)]));
            }
            else if (s.find("歐") != -1 && s.find("歐貝爾") == -1 && s.find("歐虧") == -1) {
                bot.message_create(message(event.msg.channel_id, europe[mt() % size(europe)]));
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
            else if (v[0] == "草" || s.find("笑死") != -1
                || (s.find("w") != -1 && s.find("a") == -1 && s.find("t") == -1 && s.find("e") == -1 && s.find("s") == -1
                    && s.find("l") == -1 && s.find("d") == -1 && s.find("i") == -1 && s.find("m") == -1 && s.find("o") == -1
                    && s.find("p") == -1 && s.find("y") == -1 && s.find("^") == -1)) {
                bot.message_create(message(event.msg.channel_id, kusa[mt() % size(kusa)]));
            }
            else if(s.find("kusa") != -1) {
                bot.message_create(message(event.msg.channel_id, kusa[mt() % size(kusa)]));
                }
            else if (v[0] == "gay" || s.find("甲") != -1 || s.find("🏳️‍🌈") != -1 || s.find("🈸") != -1 
                || v[0] == "給" || (s.find("是給") != -1 && s.find("倒是") == -1) || v[0] == "超給") {
                bot.message_create(message(event.msg.channel_id, gay[mt() % size(gay)]));
            }
            else if (s.find("fbi") != -1 || s.find("ㄌㄌㄎ") != -1 || s.find("FBI") != -1) {
                bot.message_create(message(event.msg.channel_id, fbi[mt() % size(fbi)]));
            }
            else if (s.find("大") != -1 && s.find("奶") != -1) {
                bot.message_create(message(event.msg.channel_id, boobs[mt() % size(boobs)]));
            }
            else if (s.find("tsuna") != -1 || v[0] == "<:pte_lemon:986265384992772166>" || s.find("三小") != -1) {
                bot.message_create(message(event.msg.channel_id, wat[mt() % size(wat)]));
            }
            else if (s.find("mygo") != -1 || s.find("買夠") != -1 || s.find("MyGO") != -1) {
                bot.message_create(message(event.msg.channel_id, mygo[mt() % size(mygo)]));
            }

            //雀魂等待序列程式碼
            else if ((s.find("雀") != -1 && s.find("待") != -1) || s.find("mjw") != -1) {
                ch = event.msg.channel_id;
                for (auto it = mwl.begin(); it != mwl.end(); ++it) {
                    if (*it == au) {
                        bot.message_create(message(ch, "你已在等待開局序列中").set_reference(event.msg.id));
                        sta[1] = 0;
                        break;
                    }
                }
                if (sta[1] == 1) {
                    bot.message_create(message(ch, "等待區人數+1").set_reference(event.msg.id));
                    mwl.push_back(au);
                    bot.message_create(message(ch, "https://imgur.com/o2BP09j"));
                }
                bot.message_create(message(ch, mjnre(mwl.size())));
                sta[1] = 1;

                bot.start_timer([&bot](const timer& timer1) {
                    if (mwl.size() != NULL) {
                        mwl.clear();
                        bot.message_create(message(ch, "等待過久、麻將等待序列已清空"));
                    }
                    else
                        bot.stop_timer(timer1);
                    //bot.message_create(message(tid, "主人、序列好像已經清空了、但您曾囑咐我每次都要報告、所以我還是出現在這裡說一聲了！"));
                }, 1800);
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
                bot.message_create(message(event.msg.channel_id, mjuse).set_reference(event.msg.id));
            }

            //抽卡相關程式碼
            else if (v[0] == "抽" || v[0] == "gacha" || v[0] == "抽卡") {
                bot.message_create(message(event.msg.channel_id, gacha.ga(v[1], v[2])));
            }
            else if (v[0] == "!gacha") {
                if (stoi(v[1]) > 1000)
                    bot.message_create(message(event.msg.channel_id, "主人的...數字...好大...\n巧克力～啊！～快要壞掉了......"));
                else {
                    gatimes = v[1];
                    bot.message_create(
                        message(event.msg.channel_id, "主人要抽什麼 " + v[1] + " 抽呢？")
                        .add_component(
                            component().add_component(
                                component().set_label("fgo").
                                set_type(cot_button).
                                set_style(cos_danger).
                                set_id("fgoga")
                            )
                        )
                        .add_component(
                            component().add_component(
                                component().set_label("明日方舟").
                                set_type(cot_button).
                                set_style(cos_danger).
                                set_id("arkga")
                            )
                        )
                        .add_component(
                            component().add_component(
                                component().set_label("公主連結").
                                set_type(cot_button).
                                set_style(cos_danger).
                                set_id("pcrga")
                            )
                        )
                    );
                }
            }
            else if (s == "!getgacha") {
                bot.message_create(
                    message(event.msg.channel_id, "主人要抽什麼遊戲抽到有呢？")
                    .add_component(
                        component().add_component(
                            component().set_label("fgo").
                            set_type(cot_button).
                            set_style(cos_danger).
                            set_id("fgogega")
                        )
                    )
                    .add_component(
                        component().add_component(
                            component().set_label("明日方舟").
                            set_type(cot_button).
                            set_style(cos_danger).
                            set_id("arkgega")
                        )
                    )
                    .add_component(
                        component().add_component(
                            component().set_label("公主連結").
                            set_type(cot_button).
                            set_style(cos_danger).
                            set_id("pcrgega")
                        )
                    )
                );
            }
            else if (v[0] == "抽到有") {
                bot.message_create(message(event.msg.channel_id, gacha.get(v[1])));
                /*if (v[1] == "pcr" || v[1] == "公連" || v[1] == "PCR")
                    bot.message_create(message(event.msg.channel_id, pcrget()));
                else if (v[1] == "fgo" || v[1] == "居歐" || v[1] == "FGO")
                    bot.message_create(message(event.msg.channel_id, fgoget()));
                else
                    bot.message_create(message(event.msg.channel_id, qre(tkuse, token[0], token[1])));*/
            }
            else if (v[0] == "機率" || v[0] == "抽卡機率") {
                if (v[1] == "pcr" || v[1] == "公連")
                    txt = "★★★角色　3%\n★★角色　  18%\n★角色　　 79%";
                else if (v[1] == "fgo" || v[1] == "居歐" || v[1] == "FGO")
                    txt = "銀卡<:fgo_K3:1107145411724054532> 96%\n金卡<:fgo_K2:1107145363795746977> 3%\n彩卡<:fgo_K1:1107145268681519114> 1%";
                else if (v[1] == "ark" || v[1] == "方舟")
                    txt = "六星<:ark6:1107953803057188905> 2%\n五星<:ark5:1107953865602637824> 8%\n四星<:ark4:1107953907377901579> 30%\n三星<:ark3:1107953947353808947> 60%\n\n不要問我為什麼用狙信物，我絕對沒有對某隻六星狙有特別的偏好";
                else
                    bot.message_create(message(event.msg.channel_id, qre(tkuse, token[0], token[1])).set_reference(event.msg.id));

                bot.message_create(message(event.msg.channel_id, txt).set_reference(event.msg.id));
            }
            else if (v[0] == "亂數測試") {
                message msg(event.msg.channel_id, gacha.rdt());
                bot.message_create(msg.set_reference(event.msg.id));
            }
            else if (v[0] == "抽卡說明") {
                txt = "目前支援fgo、明日方舟與公主連結\nfgo與公主連結支援抽到有功能（有保底）\n輸入「!gacha (抽數)」即會出現選項";
                message msg(event.msg.channel_id, txt);
                bot.message_create(msg.set_reference(event.msg.id));
            }

            //素材查詢程式碼
            else if (v[0] == "素材" || v[0] == "fgo素材") {
                sta[1] = FALSE;
                for (int i = 0; i < size(mat); i++) {
                    while (v[1] == mat[i][0]) {
                        bot.message_create(message(event.msg.channel_id, "```" + mat[i][1] + "```").set_reference(event.msg.id));
                        sta[1] = TRUE;
                        break;
                    }
                }
                if (sta[1] == FALSE) {
                    message msg(event.msg.channel_id, qre(tkuse, token[0], token[1]));
                    bot.message_create(msg.set_reference(event.msg.id));
                }
            }

            //會被抓去瑟瑟程式碼
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
            else if (tkuse == token[0] && (s.find("貓") != -1 || s.find("ショコラ") != -1
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
                embed embed = dpp::embed().
                    set_color(colors::scarlet_red).
                    set_title("CREATOR").
                    set_url("https://github.com/kevinwei1029").
                    set_author("anime.photos.tw", "https://www.instagram.com/anime.photos.tw/", "https://imgur.com/mYfhOY7").
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
                        "木棉花竟然要代理虹團OVA木棉花我大哥",
                        "木棉花竟然要代理虹團OVA木棉花我大哥\n木棉花竟然要代理虹團OVA木棉花我大哥"
                    ).
                    set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                    set_footer(embed_footer().set_text("我好喜歡小雪菜").set_icon("https://imgur.com/mYfhOY7")).
                    set_timestamp(time(0));

                //reply with the created embed
                bot.message_create(message(event.msg.channel_id, embed).set_reference(event.msg.id));
            }
            else if (s == "!help" || s.find("!function") != -1) {
                /* create the embed */
                embed embed = dpp::embed().
                    set_color(colors::sti_blue).
                    set_title("FUNCTIONS").
                    set_url("https://github.com/kevinwei1029").
                    set_author("anime.photos.tw", "https://www.instagram.com/anime.photos.tw/", "https://imgur.com/mYfhOY7").
                    set_description("優木雪菜我婆！").
                    set_thumbnail("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                    add_field(
                        "可用斜線程式碼",
                        "new waifu \ncattie \nark charactors \nbruh"
                    ).
                    add_field(
                        "! 指令",
                        "help \ncreator \nbutton \ngacha \ngetgacha"
                    ).
                    add_field(
                        "^ 指令",
                        "支援n站、jm、w站車號，以及pixiv圖片編號（8~9碼）"
                    ).
                    add_field(
                        "抽卡",
                        "目前支援fgo、明日方舟與公主連結\nfgo與公主連結支援抽到有功能（有保底）"
                    ).
                    add_field(
                        "抽卡功能使用公式",
                        "!gacha （抽數、半形數字）"
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
                         單獨發「等待人數」\n機器人會告訴你現在有哪些人跟多少人在等待開局\n\
                         單獨發「退出等待」\n機器人會把你移出等待序列"
                    ).
                    add_field(
                        "最後更新日期",
                        "2023/8/25"
                    ).
                    set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                    set_footer(embed_footer().set_text("我好喜歡小浠").set_icon("https://imgur.com/mYfhOY7")).
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
                            set_emoji("😄").
                            //set_emoji(u8"😄").
                            set_style(cos_danger).
                            set_id("你媽死了")
                        )
                    )
                );
            }
            else if (s == "!select") {
                /* Create a message containing an action row, and a select menu within the action row. */
                message m(event.msg.channel_id, "this text has a select menu");
                m.add_component(
                    component().add_component(
                        component().
                        set_type(cot_selectmenu).
                        set_placeholder("Pick something").
                        //add_select_option(select_option("label1", "value1", "description1").set_emoji(u8"😄")).
                        //add_select_option(select_option("label2", "value2", "description2").set_emoji(u8"🙂")).
                        add_select_option(select_option("label1", "value1", "description1").set_emoji("😄")).
                        add_select_option(select_option("label2", "value2", "description2").set_emoji("🙂")).
                        set_id("myselid")
                    )
                );
                event.reply(m);
            }
        }
        else if (sta[0] != 1) {
            if (s.find("起來") != -1) {
                sta[0] = 1;
                bot.message_create(message(event.msg.channel_id, "好的，我回來了").set_reference(event.msg.id));
            }
            else if (s.find("狀態") != -1 || sta[0] == 0) {
                bot.message_create(message(event.msg.channel_id, "巧克力正在等待被喚醒的休息").set_reference(event.msg.id));
            }
            else if (s.find("狀態") != -1 || sta[0] == 2) {
                bot.message_create(message(event.msg.channel_id, "巧克力正在有計時的休息").set_reference(event.msg.id));
            }
            else if (s.find("狀態") != -1) {
                bot.message_create(message(event.msg.channel_id, "sta[0] = " + to_string(sta[0])).set_reference(event.msg.id));
            }
        }
        //else bot.message_create(message(event.msg.channel_id, "巧克力也不知道你是怎麼跑到這裡來的，大bug快點回報給主人吧！"));
    });

    //When a user clicks your button, the on_button_click event will fire, containing the custom_id you defined in your button.
    bot.on_button_click([&bot](const button_click_t & event) {
        Decodejson* del = new Decodejson;
        if (del->getcont().find("共計抽到") != -1) {
            //cerr << "message id = " << del->getms() << "\nchannel id = " << del->getch() << "\ncontent = " << del->getcont();
            bot.message_delete(del->getms(), del->getch());
        }
        delete del;
        s = event.custom_id;
        if (s == "fgoga")
            event.reply( gacha.ga("fgo", gatimes) );
        else if (s == "arkga")
            event.reply(gacha.ga("ark", gatimes));
        else if (s == "pcrga")
            event.reply(gacha.ga("pcr", gatimes));
        else if (s == "fgogega")
            event.reply( gacha.get("fgo"));
        else if (s == "pcrgega")
            event.reply( gacha.get("pcr"));
        else if (s == "arkgega")
            event.reply(gacha.get("ark"));
        else if (s.find("rest") != -1) {
            sta[0] = 2;

            if (s == "rest30m") {
                event.reply("那我先去休息30分鐘了");
                bot.start_timer([&bot](const timer& rest) {
                    sta[0] = 1;
                    bot.message_create(message(968693698206519356, "休息時間結束了，我回來了！"));
                    bot.stop_timer(rest);
                }, 1800);  //  測試中設為十秒
            }
            else if (s == "rest1h") {
                event.reply("那我先去休息1小時了");
                bot.start_timer([&bot](const timer& rest) {
                    sta[0] = 1;
                    bot.message_create(message(968693698206519356, "休息時間結束了，我回來了！"));
                    bot.stop_timer(rest);
                }, 3600);
            }
            else if (s == "resttc") {
                event.reply("那我先去休息了");
                sta[0] = 0;
            }
            else {
                event.reply("You send a invalid custom id : " + s);
            }
        }
        else
            event.reply("You send a invalid custom id : " + s);
    });

    bot.start(st_wait);
    return 0;
}