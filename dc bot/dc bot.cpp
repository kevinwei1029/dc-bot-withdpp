#include <iostream> 
#include <string> 
#include <dpp/dpp.h>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <random>

using namespace std;

string nero[16] = {"https://cdn.discordapp.com/attachments/968693698206519356/1092538926687858828/1680551962912.jpg",
                  "https://media.discordapp.net/attachments/968693698206519356/1092538926914359466/1680551964443.jpg?width=1050&height=735",
                  "https://cdn.discordapp.com/attachments/968693698206519356/1092709412789030972/16051910383634.png",
                  "https://cdn.discordapp.com/attachments/933710044917288963/1092728926054400030/70027330_p0_master1200.png",
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093091882638254110/90495379_p0.png",
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092021884956702/106295232_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092114721689620/100877791_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092323023392818/106192093_p0.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092538400903188/106416803_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092623398477824/100508530_p0.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092717183119381/98878276_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092779489505360/71238969_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092836917919814/90495379_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093092898981036053/89517369_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093095677170565150/67090381_p0_master1200.png" ,
                  "https://cdn.discordapp.com/attachments/968693698206519356/1093095720455782441/91937298_p0_master1200.png" };

string exusiai[23] = {
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364786424721458/74871383_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364800966369371/79067802_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364833891663892/79640496_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364858835173466/101872504_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364890313437184/105525478_p0.png",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364936853422231/103486827_p0.png",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364960098275459/105829323_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093364993694638110/101933810_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365024522772491/104753423_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365055019548744/99347539_p0_1.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365087139536916/83439562_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365103606374502/93266233_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365117548236910/91879173_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365135009132585/103866984_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365150003757056/101028272_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365164444745768/102634213_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365189212119152/79405727_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365203921543270/105116769_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365220786851901/101872743_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365235647258734/104348996_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365266253086770/91809487_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365280455000164/97693106_p0.jpg",
    "https://cdn.discordapp.com/attachments/970373508209201262/1093365918169575494/105844530_p0.jpg"
};

string truee[4] = {"https://cdn.discordapp.com/attachments/967070448149991434/1092781118702497872/J4RQDMD.png", 
                  "https://cdn.discordapp.com/attachments/968693698206519356/1092781449641463859/1648880999715.png", 
                  "https://cdn.discordapp.com/attachments/968693698206519356/1092781578129772664/1652857835934.png", 
                  "https://cdn.discordapp.com/attachments/968693698206519356/1092781749743931432/1672283745170-ba37455ba44240a293fb5cb3531811f9-500x333.png"};

int main() {

    dpp::cluster bot("MTA5MjQ5NzAwMDk0NTE2MDMyNA.GL40Uc.3ZLf7UNW1YZ7DFzU1z2Hx0OWjOvUZ-fZmml7G8", dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    int length = 0;

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");

        }else if (event.command.get_command_name() == "new_waifu") {
            event.reply("https://cdn.discordapp.com/attachments/966729542800658442/1092428172705931355/FB_IMG_1625811644856.jpg");

        }else if (event.command.get_command_name() == "cattie") {
            event.reply("https://cdn.discordapp.com/attachments/973282252186349588/1083963031077265528/IMG_6734.jpg");

        }else if (event.command.get_command_name() == "nero") {
            mt19937 mt(time(nullptr));
            string ne = nero[ mt() % 16];
            event.reply(ne);

        }else if (event.command.get_command_name() == "bruh") {
            event.reply("https://cdn.discordapp.com/attachments/933710044917288963/1092725740195295252/9k.png");

        }else if (event.command.get_command_name() == "true") {
            mt19937 mt(time(nullptr));
            string tr = truee[ mt() % 4];
            event.reply(tr);

        }else if (event.command.get_command_name() == "help") {
            event.reply("NOTE: \nI can only read your texts and reply in English!!! \n\nslash command:\nping \nnew waifu \ncattie \nnero \nbruh \ntrue \n\n! command: \nhelp \ncreator \nhttps://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png");
        
        }else if (event.command.get_command_name() == "exusiai") {
            mt19937 mt(time(nullptr));
            string ex = exusiai[mt() % 23];
            event.reply(ex);

        }
        });

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
        }
        });
    
    /* Message handler to look for a command*/
    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        if (event.msg.content == "file") {
            // create a message
            dpp::message msg(event.msg.channel_id, "Hey there, i've got a new file!");

            // attach the file to the message
            msg.add_file("foobar.txt", dpp::utility::read_file("path_to_your_file.txt"));

            // send the message
            bot.message_create(msg);
        }else if (event.msg.content == "europe") {
            // create a message
            dpp::message msg(event.msg.channel_id, "da lao");

            // send the message
            bot.message_create(msg);
        }else if (event.msg.content == "2.6 forecast") {
            // create a message
            dpp::message msg(event.msg.channel_id, "check this!");

            // attach the file to the message
            msg.add_file("fgo.txt", dpp::utility::read_file("H:\""));

            // send the message
            bot.message_create(msg);
        }/*else if (event.msg.content == "!rs" || event.msg.content == "!r") {
            // create a message
            dpp::message msg(event.msg.channel_id, "https://cdn.discordapp.com/attachments/933710044917288963/1092771938272805024/IMG_8429.jpg");

            // send the message
            bot.message_create(msg);
        }*/else if (event.msg.content == "true") {
            mt19937 mt(time(nullptr));
            string tr = truee[mt() % 4];
            // create a message
            dpp::message msg(event.msg.channel_id, tr);

            // send the message
            bot.message_create(msg);
        }
        });

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
                    "donate 5 usd",
                    "and give the creator a cup of coffee"
                ).
                add_field(
                    "the creator has been upset",
                    "since Tomori had resigned"
                ).
                set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                set_footer(dpp::embed_footer().set_text("Some footer text here").set_icon("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png")).
                set_timestamp(time(0));

            /* reply with the created embed */
            bot.message_create(dpp::message(event.msg.channel_id, embed).set_reference(event.msg.id));

        }else if (event.msg.content == "!help" || event.msg.content == "!function") {

            /* create the embed */
            dpp::embed embed = dpp::embed().
                set_color(dpp::colors::sti_blue).
                set_title("function").
                set_url("https://www.youtube.com/channel/UC04oBjEp3AKCMVMJAumw0oA").
                set_author("anime.photos.tw", "https://idol.st/allstars/cards", "https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                set_description("Yuuki Sutsuna is my waifu").
                set_thumbnail("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                add_field(
                    "NOTE :", 
                    "I can only read your texts and reply IN ENGLISH!!! "
                ).
                add_field(
                    "slash command",
                    "ping \nnew waifu \ncattie \nnero \nbruh \ntrue \nexusiai"
                ).
                add_field(
                    "! command",
                    "help \ncreator"
                ).
                set_image("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png").
                set_footer(dpp::embed_footer().set_text("Some footer text here").set_icon("https://i.idol.st/u/card/art/2x/841UR-Yuki-Setsuna-Oh-My-Gosh-Magician-of-the-Fiery-Flame-sqt9AE.png")).
                set_timestamp(time(0));

            /* reply with the created embed */
            bot.message_create(dpp::message(event.msg.channel_id, embed).set_reference(event.msg.id));
        }
        });

    bot.start(dpp::st_wait);
    return 0;
}

