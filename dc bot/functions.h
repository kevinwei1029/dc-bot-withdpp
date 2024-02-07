#include "string.h"

int x = 0, y = 0;

//自定義函式
string qre(string tkusing, string tk0, string tk1) {
    if (tkusing == tk0)
        return "但......チョコラ不知道主人在說什麼欸？";
        //return "現在登入的是チョコラ";
    else if (tkusing == tk1)
        return "再鬧\n我就叫M3捅爆你屁眼";
        //return "現在登入的是凱爾希";
    else
        return "哇程式竟然抓不到是哪一隻機器人登入\n可以趕快回報給開發者這個bug";
}
string mjnre(int size) {
    switch (size) {
    case 0:
        return "現在沒有人在等候";
        break;

    case 1: case 2:
        return "還缺 " + to_string(3-size) + " 人才能夠開局";
        break;

    case 3:
        return "現在有三人在等待開局、可以打三麻";
        break;

    case 4:
        return "現在有四人在等待開局、可以打四麻或修羅了";
        break;

    case 5: case 6:
        return "如果已經開局了，記得要清空序列喔？\n不然就趕緊開始遊戲吧？";
        break;

    default :
        return "奇怪的vector長度出現了，快叫我老木過來看";
    }
};
void cmd(string s) {
    wchar_t command[1000] = { 0 };
    for (int i = 0; i < s.size(); i++) {
        command[i] = s[i];
    }
    //txt = WinExec(s.c_str(), SW_SHOWNORMAL);
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // 初始化 STARTUPINFO 結構
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    // 創建子進程
    if (!CreateProcess(
        NULL,                                   // 指定要執行的應用程式的路徑（這裡為空，表示使用命令提示字元）
        command,                                   // 指定命令列參數（使用存儲在字串內的命令）
        NULL,                                   // 安全性屬性（默認為 NULL）
        NULL,                                   // 安全性屬性（默認為 NULL）
        FALSE,                                  // 指定是否繼承父進程的虛擬控制台
        0,                                      // 指定創建標誌（默認為 0）
        NULL,                                   // 指定新進程的環境塊（默認為 NULL）
        NULL,                                   // 指定新進程的當前目錄（默認為 NULL）
        &si,                                    // 指向 STARTUPINFO 結構的指針
        &pi                                     // 指向 PROCESS_INFORMATION 結構的指針
    )) {
        std::cerr << "無法創建進程" << std::endl;
    }

    // 等待子進程結束
    //WaitForSingleObject(pi.hProcess, INFINITE);

    // 釋放相關資源
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

}

class Gacha {

private:

    const float pcrgp = 0.03, pcrsp = 0.1, fgogp = 0.01, fgosp = 0.03, arkrp = 0.02, arkgp = 0.08, arksp = 0.3;
    float rp = 0.0, gp = 0.0, sp = 0.0;
    int ts = 0;
    int res[4] = { 0 };  //  依序是：6, 5, 4, 3 或：空，彩，金，銀

    void setp(string g) {
        if ((g == "pcr" || g == "公連" || g == "PCR")) {
            this->rp = 0.0;
            this->gp = pcrgp;
            this->sp = pcrsp;
        }
        else if ((g == "fgo" || g == "居歐" || g == "FGO")) {
            this->rp = 0.0;
            this->gp = fgogp;
            this->sp = fgosp;
        }
        else if ((g == "ark" || g == "方舟" || g == "ARK")) {
            this->rp = arkrp;
            this->gp = arkgp;
            this->sp = arksp;
        }
        else
            txt = "巧克力不知道你在說什麼欸～";
    }

    void ga1() {
        int t = mt() % 100;
        if (rp != 0 && t <= 100 * rp) res[0]++;  //  抽中彩卡
        else if (t <= 100 * (rp + gp)) res[1]++;
        else if (t <= 100 * (rp + gp + sp)) res[2]++;
        else res[3]++;
    }
    
    string reply(string g){
        if ((g == "pcr" || g == "公連" || g == "PCR")) {
            return ("抽了**" + to_string(ts) + "**抽\n共計抽到：\n**" + to_string(res[3]) + "**張銀卡 <:pcr1:1117798654548377641>\n**"
                + to_string(res[2]) + "**張金卡 <:pcr2:1117798436427804754>\n**" + to_string(res[1]) + "**張彩卡 <:pcr3:1117798715957194923>\n");
        }
        else if ((g == "fgo" || g == "居歐" || g == "FGO")) {
            return ("抽了**" + to_string(ts) + "**抽\n共計抽到：\n**" + to_string(res[3]) + "**張銀卡<:fgo_K3:1107145411724054532>\n**"
                + to_string(res[2]) + "**張金卡<:fgo_K2:1107145363795746977>\n**" + to_string(res[1]) + "**張彩卡<:fgo_K1:1107145268681519114>\n");
        }
        else if ((g == "ark" || g == "方舟" || g == "ARK")) {
            return ("抽了**" + to_string(ts) + "**抽\n共計抽到：\n**" + to_string(res[3]) + "**張三星<:ark3:1107953947353808947>\n**"
                + to_string(res[2]) + "**張四星<:ark4:1107953907377901579>\n**" + to_string(res[1]) + "**張五星<:ark5:1107953865602637824>\n**"
                + to_string(res[0]) + "**張六星<:ark6:1107953803057188905>\n");
        }
        else
            return "巧克力不知道你在說什麼欸～";
    }

public:

    string ga(string game, string times){
        txt = "";
        ts = rp = gp = sp = res[0] = res[1] = res[2] = res[3] = 0;
        this->ts = stoi(times);
        if (ts > 500) return "主人的...數字...好大...\n巧克力～啊！～快要壞掉了......";
        this->setp(game);
        if (txt != "") return txt;
        for (int i = 0; i < ts; i++) {
            this->ga1();
        }
        return this->reply(game);
    }

    string get(string game){
        txt = "";
        ts = rp = gp = sp = res[0] = res[1] = res[2] = res[3] = 0;
        this->setp(game);
        if (txt != "") return txt;
        
        if (rp != 0) {  //  方舟
            while (!res[0] && ts < 50) {
                this->ga1();
                ts++;
            }
            while (!res[0]) {
                this->ga1();
                ts++;
                this->rp = this->rp + 0.02;
            }
            return ("抽了**" + to_string(ts) + "**抽\n共計抽到：\n**" + to_string(res[3]) + "**張三星<:ark3:1107953947353808947>\n**"
                + to_string(res[2]) + "**張四星<:ark4:1107953907377901579>\n**" + to_string(res[1]) + "**張五星<:ark5:1107953865602637824>\n**"
                + to_string(res[0]) + "**張六星<:ark6:1107953803057188905>\n\n出貨當下彩率 = " + to_string(rp));
        }
        else if (gp = 0.03) {  //  公連
            while (!res[1] && ts < 200) {
                this->ga1();
                ts++;
            }
            if (!res[1]) {
                return ("so sad你保底了\n\n抽到了：\n**" + to_string(res[3]) + "**張銀卡<:pcr1:1117798654548377641>\n**"
                    + to_string(res[2]) + "**張金卡<:pcr2:1117798436427804754>\n");
            }
        }
        else if (gp = 0.01) {  //  fgo
            while (!res[1] && ts < 329) {
                this->ga1();
                ts++;
            }
            if (!res[1]) {
                return ("so sad你保底了\n\n抽到了：\n**" + to_string(res[3]) + "**張銀卡<:fgo_K3:1107145411724054532>\n**"
                    + to_string(res[2]) + "**張金卡<:fgo_K2:1107145363795746977>");
            }
        }

        return this->reply(game);
    }

    string rdt() {
        txt = "";
        int* p = new int[10];
        int num;
        for (int i = 0; i < 10; i++) {
            *(p + i) = 0;
        }
        for (int i = 0; i < 500; i++) {
            num = mt() % 100;
            *(p + (num / 10)) += 1;
        }
        txt = "在500次試驗裡面：\n";
        for (int i = 10; i < 101; i += 10) {
            txt += to_string(i - 9) + " ~ " + to_string(i) + "出現了 " + to_string(*(p + (i / 10 - 1))) + " 次、\n";
        }
        delete [] p;
        txt.pop_back();
        return txt;
    }

    string rdt(string times) {
        txt = "";
        int* p = new int[10];
        int num;
        for (int i = 0; i < 10; i++) {
            *(p + i) = 0;
        }
        for (int i = 0; i < stoi(times); i++) {
            num = mt() % 100;
            *(p + (num / 10)) += 1;
        }
        txt = "在" + times + "次試驗裡面：\n";
        for (int i = 10; i < 101; i += 10) {
            txt += to_string(i - 9) + " ~ " + to_string(i) + "出現了 " + to_string(*(p + (i / 10 - 1))) + " 次、\n";
        }
        delete[] p;
        return txt;
    }
};

class Acceed {

private:

    vector<pair<int, string>> yaju;

    string yjp(int num) {
        if (num > 10000000) return "數字太大了\n扼啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊";
        bool ism = false;
        string equ;

        if (num < 0) {
            equ += "-(";
            ism = true;
            num = num * -1;
        }

        if (num > 114514 * 2) {
            equ += "114514\\*(" + yjp(num/114514) + ")+";
            num %= 114514;
        }
        for (int i = 0; i < yaju.size(); i++) {
            while (num >= yaju[i].first && num) {
                equ += yaju[i].second + "+";
                num -= yaju[i].first;
            }
        }
        
        equ.pop_back();
        if (ism) equ += ")";
        return equ;
    };
    
public:

    //  make yaju pair
    Acceed(){
        yaju.push_back(make_pair(114514, "114514"));
        yaju.push_back(make_pair(58596, "114\\*514"));
        yaju.push_back(make_pair(49654, "11\\*4514"));
        yaju.push_back(make_pair(45804, "11451\\*4"));
        yaju.push_back(make_pair(23256, "114\\*51\\*4"));
        yaju.push_back(make_pair(22616, "11\\*4\\*514"));
        yaju.push_back(make_pair(19844, "11\\*451\\*4"));
        yaju.push_back(make_pair(16030, "1145\\*14"));
        yaju.push_back(make_pair(14515, "1+14514"));
        yaju.push_back(make_pair(14514, "1\\*14514"));
        yaju.push_back(make_pair(14513, "-1+14514"));
        yaju.push_back(make_pair(11455, "11451+4"));
        yaju.push_back(make_pair(11447, "11451-4"));
        yaju.push_back(make_pair(9028, "(1+1)\\*4514"));
        yaju.push_back(make_pair(8976, "11\\*4\\*51\\*4"));
        yaju.push_back(make_pair(7980, "114\\*5\\*14"));
        yaju.push_back(make_pair(7710, "(1+14)\\*514"));
        yaju.push_back(make_pair(7197, "1+14\\*514"));
        yaju.push_back(make_pair(7196, "1\\*14\\*514"));
        yaju.push_back(make_pair(7195, "-1+14\\*514"));
        yaju.push_back(make_pair(6930, "11\\*45\\*14"));
        yaju.push_back(make_pair(6682, "(1-14)\\*-514"));
        yaju.push_back(make_pair(6270, "114\\*(51+4)"));
        yaju.push_back(make_pair(5818, "114\\*51+4"));
        yaju.push_back(make_pair(5810, "114\\*51-4"));
        yaju.push_back(make_pair(5808, "(1+1451)\\*4"));
        yaju.push_back(make_pair(5805, "1+1451\\*4"));
        yaju.push_back(make_pair(5804, "1\\*1451\\*4"));
        yaju.push_back(make_pair(5803, "-1+1451\\*4"));
        yaju.push_back(make_pair(5800, "(1-1451)\\*-4"));
        yaju.push_back(make_pair(5725, "1145\\*(1+4)"));
        yaju.push_back(make_pair(5698, "11\\*(4+514)"));
        yaju.push_back(make_pair(5610, "-11\\*(4-514)"));
        yaju.push_back(make_pair(5358, "114\\*(51-4)"));
        yaju.push_back(make_pair(5005, "11\\*(451+4)"));
        yaju.push_back(make_pair(4965, "11\\*451+4"));
        yaju.push_back(make_pair(4957, "11\\*451-4"));
        yaju.push_back(make_pair(4917, "11\\*(451-4)"));
        yaju.push_back(make_pair(4584, "(1145+1)\\*4"));
        yaju.push_back(make_pair(4580, "1145\\*1\\*4"));
        yaju.push_back(make_pair(4576, "(1145-1)\\*4"));
        yaju.push_back(make_pair(4525, "11+4514"));
        yaju.push_back(make_pair(4516, "1+1+4514"));
        yaju.push_back(make_pair(4515, "1+1\\*4514"));
        yaju.push_back(make_pair(4514, "1-1+4514"));
        yaju.push_back(make_pair(4513, "-1\\*1+4514"));
        yaju.push_back(make_pair(4512, "-1-1+4514"));
        yaju.push_back(make_pair(4503, "-11+4514"));
        yaju.push_back(make_pair(4112, "(1+1)\\*4\\*514"));
        yaju.push_back(make_pair(3608, "(1+1)\\*451\\*4"));
        yaju.push_back(make_pair(3598, "(11-4)\\*514"));
        yaju.push_back(make_pair(3435, "-1145\\*(1-4)"));
        yaju.push_back(make_pair(3080, "11\\*4\\*5\\*14"));
        yaju.push_back(make_pair(3060, "(11+4)\\*51\\*4"));
        yaju.push_back(make_pair(2857, "1+14\\*51\\*4"));
        yaju.push_back(make_pair(2856, "1\\*14\\*51\\*4"));
        yaju.push_back(make_pair(2855, "-1+14\\*51\\*4"));
        yaju.push_back(make_pair(2850, "114\\*5\\*(1+4)"));
        yaju.push_back(make_pair(2736, "114\\*(5+1)\\*4"));
        yaju.push_back(make_pair(2652, "(1-14)\\*51\\*-4"));
        yaju.push_back(make_pair(2570, "1\\*(1+4)\\*514"));
        yaju.push_back(make_pair(2475, "11\\*45\\*(1+4)"));
        yaju.push_back(make_pair(2420, "11\\*4\\*(51+4)"));
        yaju.push_back(make_pair(2280, "114\\*5\\*1\\*4"));
        yaju.push_back(make_pair(2248, "11\\*4\\*51+4"));
        yaju.push_back(make_pair(2240, "11\\*4\\*51-4"));
        yaju.push_back(make_pair(2166, "114\\*(5+14)"));
        yaju.push_back(make_pair(2068, "11\\*4\\*(51-4)"));
        yaju.push_back(make_pair(2067, "11+4\\*514"));
        yaju.push_back(make_pair(2058, "1+1+4\\*514"));
        yaju.push_back(make_pair(2057, "1/1+4\\*514"));
        yaju.push_back(make_pair(2056, "1/1\\*4\\*514"));
        yaju.push_back(make_pair(2055, "-1/1+4\\*514"));
        yaju.push_back(make_pair(2054, "-1-1+4\\*514"));
        yaju.push_back(make_pair(2045, "-11+4\\*514"));
        yaju.push_back(make_pair(2044, "(1+145)\\*14"));
        yaju.push_back(make_pair(2031, "1+145\\*14"));
        yaju.push_back(make_pair(2030, "1\\*145\\*14"));
        yaju.push_back(make_pair(2029, "-1+145\\*14"));
        yaju.push_back(make_pair(2024, "11\\*(45+1)\\*4"));
        yaju.push_back(make_pair(2016, "-(1-145)\\*14"));
        yaju.push_back(make_pair(1980, "11\\*45\\*1\\*4"));
        yaju.push_back(make_pair(1936, "11\\*(45-1)\\*4"));
        yaju.push_back(make_pair(1848, "(11+451)\\*4"));
        yaju.push_back(make_pair(1824, "114\\*(5-1)\\*4"));
        yaju.push_back(make_pair(1815, "11+451\\*4"));
        yaju.push_back(make_pair(1808, "1\\*(1+451)\\*4"));
        yaju.push_back(make_pair(1806, "1+1+451\\*4"));
        yaju.push_back(make_pair(1805, "1+1\\*451\\*4"));
        yaju.push_back(make_pair(1804, "1-1+451\\*4"));
        yaju.push_back(make_pair(1803, "1\\*-1+451\\*4"));
        yaju.push_back(make_pair(1802, "-1-1+451\\*4"));
        yaju.push_back(make_pair(1800, "1\\*-(1-451)\\*4"));
        yaju.push_back(make_pair(1793, "-11+451\\*4"));
        yaju.push_back(make_pair(1760, "-(11-451)\\*4"));
        yaju.push_back(make_pair(1710, "114\\*-5\\*(1-4)"));
        yaju.push_back(make_pair(1666, "(114+5)\\*14"));
        yaju.push_back(make_pair(1632, "(1+1)\\*4\\*51\\*4"));
        yaju.push_back(make_pair(1542, "1\\*-(1-4)\\*514"));
        yaju.push_back(make_pair(1526, "(114-5)\\*14"));
        yaju.push_back(make_pair(1485, "11\\*-45\\*(1-4)"));
        yaju.push_back(make_pair(1456, "1+1451+4"));
        yaju.push_back(make_pair(1455, "1\\*1451+4"));
        yaju.push_back(make_pair(1454, "-1+1451+4"));
        yaju.push_back(make_pair(1448, "1+1451-4"));
        yaju.push_back(make_pair(1447, "1\\*1451-4"));
        yaju.push_back(make_pair(1446, "-1+1451-4"));
        yaju.push_back(make_pair(1428, "(11-4)\\*51\\*4"));
        yaju.push_back(make_pair(1386, "11\\*(4+5)\\*14"));
        yaju.push_back(make_pair(1260, "(1+1)\\*45\\*14"));
        yaju.push_back(make_pair(1159, "1145+14"));
        yaju.push_back(make_pair(1150, "1145+1+4"));
        yaju.push_back(make_pair(1149, "1145+1\\*4"));
        yaju.push_back(make_pair(1148, "1145-1+4"));
        yaju.push_back(make_pair(1142, "1145+1-4"));
        yaju.push_back(make_pair(1141, "1145-1\\*4"));
        yaju.push_back(make_pair(1140, "(1145-1)-4"));
        yaju.push_back(make_pair(1131, "1145-14"));
        yaju.push_back(make_pair(1100, "11\\*4\\*5\\*(1+4)"));
        yaju.push_back(make_pair(1056, "11\\*4\\*(5+1)\\*4"));
        yaju.push_back(make_pair(1050, "(11+4)\\*5\\*14"));
        yaju.push_back(make_pair(1036, "(1+1)\\*(4+514)"));
        yaju.push_back(make_pair(1026, "114\\*-(5-14)"));
        yaju.push_back(make_pair(1020, "1\\*(1+4)\\*51\\*4"));
        yaju.push_back(make_pair(981, "1+14\\*5\\*14"));
        yaju.push_back(make_pair(980, "1\\*14\\*5\\*14"));
        yaju.push_back(make_pair(979, "-1+14\\*5\\*14"));
        yaju.push_back(make_pair(910, "-(1-14)\\*5\\*14"));
        yaju.push_back(make_pair(906, "(1+1)\\*451+4"));
        yaju.push_back(make_pair(898, "(1+1)\\*451-4"));
        yaju.push_back(make_pair(894, "(1+1)\\*(451-4)"));
        yaju.push_back(make_pair(880, "11\\*4\\*5\\*1\\*4"));
        yaju.push_back(make_pair(836, "11\\*4\\*(5+14)"));
        yaju.push_back(make_pair(827, "11+4\\*51\\*4"));
        yaju.push_back(make_pair(825, "(11+4)\\*(51+4)"));
        yaju.push_back(make_pair(818, "1+1+4\\*51\\*4"));
        yaju.push_back(make_pair(817, "1\\*1+4\\*51\\*4"));
        yaju.push_back(make_pair(816, "1\\*1\\*4\\*51\\*4"));
        yaju.push_back(make_pair(815, "-1+1\\*4\\*51\\*4"));
        yaju.push_back(make_pair(814, "-1-1+4\\*51\\*4"));
        yaju.push_back(make_pair(805, "-11+4\\*51\\*4"));
        yaju.push_back(make_pair(784, "(11+45)\\*14"));
        yaju.push_back(make_pair(771, "1+14\\*(51+4)"));
        yaju.push_back(make_pair(770, "1\\*14\\*(51+4)"));
        yaju.push_back(make_pair(769, "(11+4)\\*51+4"));
        yaju.push_back(make_pair(761, "(1+14)\\*51-4"));
        yaju.push_back(make_pair(730, "(1+145)\\*(1+4)"));
        yaju.push_back(make_pair(726, "1+145\\*(1+4)"));
        yaju.push_back(make_pair(725, "1\\*145\\*(1+4)"));
        yaju.push_back(make_pair(724, "-1-145\\*-(1+4)"));
        yaju.push_back(make_pair(720, "(1-145)\\*-(1+4)"));
        yaju.push_back(make_pair(719, "1+14\\*51+4"));
        yaju.push_back(make_pair(718, "1\\*14\\*51+4"));
        yaju.push_back(make_pair(717, "-1-14\\*-51+4"));
        yaju.push_back(make_pair(715, "(1-14)\\*-(51+4)"));
        yaju.push_back(make_pair(711, "1+14\\*51-4"));
        yaju.push_back(make_pair(710, "1\\*14\\*51-4"));
        yaju.push_back(make_pair(709, "-1+14\\*51-4"));
        yaju.push_back(make_pair(705, "(1+14)\\*(51-4)"));
        yaju.push_back(make_pair(704, "11\\*4\\*(5-1)\\*4"));
        yaju.push_back(make_pair(688, "114\\*(5+1)+4"));
        yaju.push_back(make_pair(680, "114\\*(5+1)-4"));
        yaju.push_back(make_pair(667, "-(1-14)\\*51+4"));
        yaju.push_back(make_pair(660, "(114+51)\\*4"));
        yaju.push_back(make_pair(659, "1+14\\*(51-4)"));
        yaju.push_back(make_pair(658, "1\\*14\\*(51-4)"));
        yaju.push_back(make_pair(657, "-1+14\\*(51-4)"));
        yaju.push_back(make_pair(649, "11\\*(45+14)"));
        yaju.push_back(make_pair(644, "1\\*(1+45)\\*14"));
        yaju.push_back(make_pair(641, "11+45\\*14"));
        yaju.push_back(make_pair(632, "1+1+45\\*14"));
        yaju.push_back(make_pair(631, "1\\*1+45\\*14"));
        yaju.push_back(make_pair(630, "1\\*1\\*45\\*14"));
        yaju.push_back(make_pair(629, "1\\*-1+45\\*14"));
        yaju.push_back(make_pair(628, "114+514"));
        yaju.push_back(make_pair(619, "-11+45\\*14"));
        yaju.push_back(make_pair(616, "1\\*-(1-45)\\*14"));
        yaju.push_back(make_pair(612, "-1\\*(1-4)\\*51\\*4"));
        yaju.push_back(make_pair(611, "(1-14)\\*-(51-4)"));
        yaju.push_back(make_pair(609, "11\\*(4+51)+4"));
        yaju.push_back(make_pair(601, "11\\*(4+51)-4"));
        yaju.push_back(make_pair(595, "(114+5)\\*(1+4)"));
        yaju.push_back(make_pair(584, "114\\*5+14"));
        yaju.push_back(make_pair(581, "1+145\\*1\\*4"));
        yaju.push_back(make_pair(580, "1\\*145/1\\*4"));
        yaju.push_back(make_pair(579, "-1+145\\*1\\*4"));
        yaju.push_back(make_pair(576, "1\\*(145-1)\\*4"));
        yaju.push_back(make_pair(575, "114\\*5+1+4"));
        yaju.push_back(make_pair(574, "114\\*5/1+4"));
        yaju.push_back(make_pair(573, "114\\*5-1+4"));
        yaju.push_back(make_pair(567, "114\\*5+1-4"));
        yaju.push_back(make_pair(566, "114\\*5\\*1-4"));
        yaju.push_back(make_pair(565, "114\\*5-1-4"));
        yaju.push_back(make_pair(561, "11/4\\*51\\*4"));
        yaju.push_back(make_pair(560, "(1+1)\\*4\\*5\\*14"));
        yaju.push_back(make_pair(558, "11\\*4+514"));
        yaju.push_back(make_pair(556, "114\\*5-14"));
        yaju.push_back(make_pair(545, "(114-5)\\*(1+4)"));
        yaju.push_back(make_pair(529, "1+14+514"));
        yaju.push_back(make_pair(528, "1\\*14+514"));
        yaju.push_back(make_pair(527, "-1+14+514"));
        yaju.push_back(make_pair(522, "(1+1)\\*4+514"));
        yaju.push_back(make_pair(521, "11-4+514"));
        yaju.push_back(make_pair(520, "1+1+4+514"));
        yaju.push_back(make_pair(519, "1+1\\*4+514"));
        yaju.push_back(make_pair(518, "1-1+4+514"));
        yaju.push_back(make_pair(517, "-1+1\\*4+514"));
        yaju.push_back(make_pair(516, "-1-1+4+514"));
        yaju.push_back(make_pair(514, "(1-1)/4+514"));
        yaju.push_back(make_pair(513, "-11\\*(4-51)-4"));
        yaju.push_back(make_pair(512, "1+1-4+514"));
        yaju.push_back(make_pair(511, "1\\*1-4+514"));
        yaju.push_back(make_pair(510, "1-1-4+514"));
        yaju.push_back(make_pair(509, "11\\*45+14"));
        yaju.push_back(make_pair(508, "-1-1-4+514"));
        yaju.push_back(make_pair(507, "-11+4+514"));
        yaju.push_back(make_pair(506, "-(1+1)\\*4+514"));
        yaju.push_back(make_pair(502, "11\\*(45+1)-4"));
        yaju.push_back(make_pair(501, "1-14+514"));
        yaju.push_back(make_pair(500, "11\\*45+1+4"));
        yaju.push_back(make_pair(499, "11\\*45\\*1+4"));
        yaju.push_back(make_pair(498, "11\\*45-1+4"));
        yaju.push_back(make_pair(495, "11\\*(4+5)\\*(1+4)"));
        yaju.push_back(make_pair(492, "11\\*45+1-4"));
        yaju.push_back(make_pair(491, "11\\*45-1\\*4"));
        yaju.push_back(make_pair(490, "11\\*45-1-4"));
        yaju.push_back(make_pair(488, "11\\*(45-1)+4"));
        yaju.push_back(make_pair(481, "11\\*45-14"));
        yaju.push_back(make_pair(480, "11\\*(45-1)-4"));
        yaju.push_back(make_pair(476, "(114+5)/1\\*4"));
        yaju.push_back(make_pair(470, "-11\\*4+514"));
        yaju.push_back(make_pair(466, "11+451+4"));
        yaju.push_back(make_pair(460, "114\\*(5-1)+4"));
        yaju.push_back(make_pair(458, "11+451-4"));
        yaju.push_back(make_pair(457, "1+1+451+4"));
        yaju.push_back(make_pair(456, "1\\*1+451+4"));
        yaju.push_back(make_pair(455, "1-1+451+4"));
        yaju.push_back(make_pair(454, "-1+1\\*451+4"));
        yaju.push_back(make_pair(453, "-1-1+451+4"));
        yaju.push_back(make_pair(452, "114\\*(5-1)-4"));
        yaju.push_back(make_pair(450, "(1+1)\\*45\\*(1+4)"));
        yaju.push_back(make_pair(449, "1+1+451-4"));
        yaju.push_back(make_pair(448, "1+1\\*451-4"));
        yaju.push_back(make_pair(447, "1/1\\*451-4"));
        yaju.push_back(make_pair(446, "1\\*-1+451-4"));
        yaju.push_back(make_pair(445, "-1-1+451-4"));
        yaju.push_back(make_pair(444, "-11+451+4"));
        yaju.push_back(make_pair(440, "(1+1)\\*4\\*(51+4)"));
        yaju.push_back(make_pair(438, "(1+145)\\*-(1-4)"));
        yaju.push_back(make_pair(436, "-11+451-4"));
        yaju.push_back(make_pair(435, "-1\\*145\\*(1-4)"));
        yaju.push_back(make_pair(434, "-1-145\\*(1-4)"));
        yaju.push_back(make_pair(432, "(1-145)\\*(1-4)"));
        yaju.push_back(make_pair(412, "(1+1)\\*4\\*51+4"));
        yaju.push_back(make_pair(404, "(1+1)\\*4\\*51-4"));
        yaju.push_back(make_pair(400, "-114+514"));
        yaju.push_back(make_pair(396, "11\\*4\\*-(5-14)"));
        yaju.push_back(make_pair(385, "(11-4)\\*(51+4)"));
        yaju.push_back(make_pair(376, "(1+1)\\*4\\*(51-4)"));
        yaju.push_back(make_pair(375, "(1+14)\\*5\\*(1+4)"));
        yaju.push_back(make_pair(368, "(1+1)\\*(45+1)\\*4"));
        yaju.push_back(make_pair(363, "(1+1451)/4"));
        yaju.push_back(make_pair(361, "(11-4)\\*51+4"));
        yaju.push_back(make_pair(360, "(1+1)\\*45\\*1\\*4"));
        yaju.push_back(make_pair(357, "(114+5)\\*-(1-4)"));
        yaju.push_back(make_pair(353, "(11-4)\\*51-4"));
        yaju.push_back(make_pair(352, "(1+1)\\*(45-1)\\*4"));
        yaju.push_back(make_pair(351, "1+14\\*-5\\*-(1+4)"));
        yaju.push_back(make_pair(350, "1\\*(1+4)\\*5\\*14"));
        yaju.push_back(make_pair(349, "-1+14\\*5\\*(1+4)"));
        yaju.push_back(make_pair(341, "11\\*(45-14)"));
        yaju.push_back(make_pair(337, "1-14\\*-(5+1)\\*4"));
        yaju.push_back(make_pair(336, "1\\*14\\*(5+1)\\*4"));
        yaju.push_back(make_pair(335, "-1+14\\*(5+1)\\*4"));
        yaju.push_back(make_pair(329, "(11-4)\\*(51-4)"));
        yaju.push_back(make_pair(327, "-(114-5)\\*(1-4)"));
        yaju.push_back(make_pair(325, "-(1-14)\\*5\\*(1+4)"));
        yaju.push_back(make_pair(318, "114+51\\*4"));
        yaju.push_back(make_pair(312, "(1-14)\\*-(5+1)\\*4"));
        yaju.push_back(make_pair(300, "(11+4)\\*5/1\\*4"));
        yaju.push_back(make_pair(297, "-11\\*(4+5)\\*(1-4)"));
        yaju.push_back(make_pair(291, "11+4\\*5\\*14"));
        yaju.push_back(make_pair(286, "(1145-1)/4"));
        yaju.push_back(make_pair(285, "(11+4)\\*(5+14)"));
        yaju.push_back(make_pair(282, "1+1+4\\*5\\*14"));
        yaju.push_back(make_pair(281, "1+14\\*5/1\\*4"));
        yaju.push_back(make_pair(280, "1-1+4\\*5\\*14"));
        yaju.push_back(make_pair(279, "1\\*-1+4\\*5\\*14"));
        yaju.push_back(make_pair(278, "-1-1+4\\*5\\*14"));
        yaju.push_back(make_pair(275, "1\\*(1+4)\\*(51+4)"));
        yaju.push_back(make_pair(270, "(1+1)\\*45\\*-(1-4)"));
        yaju.push_back(make_pair(269, "-11+4\\*5\\*14"));
        yaju.push_back(make_pair(268, "11\\*4\\*(5+1)+4"));
        yaju.push_back(make_pair(267, "1+14\\*(5+14)"));
        yaju.push_back(make_pair(266, "1\\*14\\*(5+14)"));
        yaju.push_back(make_pair(265, "-1+14\\*(5+14)"));
        yaju.push_back(make_pair(260, "1\\*(14+51)\\*4"));
        yaju.push_back(make_pair(259, "1\\*(1+4)\\*51+4"));
        yaju.push_back(make_pair(257, "(1+1)/4\\*514"));
        yaju.push_back(make_pair(252, "(114-51)\\*4"));
        yaju.push_back(make_pair(251, "1\\*-(1+4)\\*-51-4"));
        yaju.push_back(make_pair(248, "11\\*4+51\\*4"));
        yaju.push_back(make_pair(247, "-(1-14)\\*(5+14)"));
        yaju.push_back(make_pair(240, "(11+4)\\*(5-1)\\*4"));
        yaju.push_back(make_pair(236, "11+45\\*(1+4)"));
        yaju.push_back(make_pair(235, "1\\*(1+4)\\*(51-4)"));
        yaju.push_back(make_pair(234, "11\\*4\\*5+14"));
        yaju.push_back(make_pair(231, "11+4\\*(51+4)"));
        yaju.push_back(make_pair(230, "1\\*(1+45)\\*(1+4)"));
        yaju.push_back(make_pair(229, "1145/(1+4)"));
        yaju.push_back(make_pair(227, "1+1+45\\*(1+4)"));
        yaju.push_back(make_pair(226, "1\\*1+45\\*(1+4)"));
        yaju.push_back(make_pair(225, "11\\*4\\*5+1+4"));
        yaju.push_back(make_pair(224, "11\\*4\\*5/1+4"));
        yaju.push_back(make_pair(223, "11\\*4\\*5-1+4"));
        yaju.push_back(make_pair(222, "1+1+4\\*(51+4)"));
        yaju.push_back(make_pair(221, "1/1+4\\*(51+4)"));
        yaju.push_back(make_pair(220, "1\\*1\\*(4+51)\\*4"));
        yaju.push_back(make_pair(219, "1+14+51\\*4"));
        yaju.push_back(make_pair(218, "1\\*14+51\\*4"));
        yaju.push_back(make_pair(217, "11\\*4\\*5+1-4"));
        yaju.push_back(make_pair(216, "11\\*4\\*5-1\\*4"));
        yaju.push_back(make_pair(215, "11\\*4\\*5-1-4"));
        yaju.push_back(make_pair(214, "-11+45\\*(1+4)"));
        yaju.push_back(make_pair(212, "(1+1)\\*4+51\\*4"));
        yaju.push_back(make_pair(211, "11-4+51\\*4"));
        yaju.push_back(make_pair(210, "1+1+4+51\\*4"));
        yaju.push_back(make_pair(209, "1+1\\*4\\*51+4"));
        yaju.push_back(make_pair(208, "1\\*1\\*4+51\\*4"));
        yaju.push_back(make_pair(207, "-1+1\\*4\\*51+4"));
        yaju.push_back(make_pair(206, "11\\*4\\*5-14"));
        yaju.push_back(make_pair(204, "(1-1)/4+51\\*4"));
        yaju.push_back(make_pair(202, "1+1-4+51\\*4"));
        yaju.push_back(make_pair(201, "1/1-4+51\\*4"));
        yaju.push_back(make_pair(200, "1/1\\*4\\*51-4"));
        yaju.push_back(make_pair(199, "1\\*-1+4\\*51-4"));
        yaju.push_back(make_pair(198, "-1-1+4\\*51-4"));
        yaju.push_back(make_pair(197, "-11+4+51\\*4"));
        yaju.push_back(make_pair(196, "-(1+1)\\*4+51\\*4"));
        yaju.push_back(make_pair(195, "(1-14)\\*5\\*(1-4)"));
        yaju.push_back(make_pair(192, "(1+1)\\*4\\*(5+1)\\*4"));
        yaju.push_back(make_pair(191, "1-14+51\\*4"));
        yaju.push_back(make_pair(190, "1\\*-14+51\\*4"));
        yaju.push_back(make_pair(189, "-11-4+51\\*4"));
        yaju.push_back(make_pair(188, "1-1-(4-51)\\*4"));
        yaju.push_back(make_pair(187, "1/-1+4\\*(51-4)"));
        yaju.push_back(make_pair(186, "1+1+(45+1)\\*4"));
        yaju.push_back(make_pair(185, "1-1\\*-(45+1)\\*4"));
        yaju.push_back(make_pair(184, "114+5\\*14"));
        yaju.push_back(make_pair(183, "-1+1\\*(45+1)\\*4"));
        yaju.push_back(make_pair(182, "1+1+45/1\\*4"));
        yaju.push_back(make_pair(181, "1+1\\*45\\*1\\*4"));
        yaju.push_back(make_pair(180, "1\\*1\\*45\\*1\\*4"));
        yaju.push_back(make_pair(179, "-1/1+45\\*1\\*4"));
        yaju.push_back(make_pair(178, "-1-1+45\\*1\\*4"));
        yaju.push_back(make_pair(177, "1+1\\*(45-1)\\*4"));
        yaju.push_back(make_pair(176, "1\\*1\\*(45-1)\\*4"));
        yaju.push_back(make_pair(175, "-1+1\\*(45-1)\\*4"));
        yaju.push_back(make_pair(174, "-1-1+(45-1)\\*4"));
        yaju.push_back(make_pair(172, "11\\*4\\*(5-1)-4"));
        yaju.push_back(make_pair(171, "114\\*(5+1)/4"));
        yaju.push_back(make_pair(170, "(11-45)\\*-(1+4)"));
        yaju.push_back(make_pair(169, "114+51+4"));
        yaju.push_back(make_pair(168, "(11+45)\\*-(1-4)"));
        yaju.push_back(make_pair(165, "11\\*-45/(1-4)"));
        yaju.push_back(make_pair(161, "114+51-4"));
        yaju.push_back(make_pair(160, "1+145+14"));
        yaju.push_back(make_pair(159, "1\\*145+14"));
        yaju.push_back(make_pair(158, "-1+145+14"));
        yaju.push_back(make_pair(157, "1\\*(1-4)\\*-51+4"));
        yaju.push_back(make_pair(154, "11\\*(4-5)\\*-14"));
        yaju.push_back(make_pair(152, "(1+1)\\*4\\*(5+14)"));
        yaju.push_back(make_pair(151, "1+145+1+4"));
        yaju.push_back(make_pair(150, "1+145\\*1+4"));
        yaju.push_back(make_pair(149, "1\\*145\\*1+4"));
        yaju.push_back(make_pair(148, "1\\*145-1+4"));
        yaju.push_back(make_pair(147, "-1+145-1+4"));
        yaju.push_back(make_pair(146, "11+45\\*-(1-4)"));
        yaju.push_back(make_pair(143, "1+145+1-4"));
        yaju.push_back(make_pair(142, "1+145\\*1-4"));
        yaju.push_back(make_pair(141, "1+145-1-4"));
        yaju.push_back(make_pair(140, "1\\*145-1-4"));
        yaju.push_back(make_pair(139, "-1+145-1-4"));
        yaju.push_back(make_pair(138, "-1\\*(1+45)\\*(1-4)"));
        yaju.push_back(make_pair(137, "1+1-45\\*(1-4)"));
        yaju.push_back(make_pair(136, "1\\*1-45\\*(1-4)"));
        yaju.push_back(make_pair(135, "-1/1\\*45\\*(1-4)"));
        yaju.push_back(make_pair(134, "114+5/1\\*4"));
        yaju.push_back(make_pair(133, "114+5+14"));
        yaju.push_back(make_pair(132, "1+145-14"));
        yaju.push_back(make_pair(131, "1\\*145-14"));
        yaju.push_back(make_pair(130, "-1+145-14"));
        yaju.push_back(make_pair(129, "114+5\\*-(1-4)"));
        yaju.push_back(make_pair(128, "1+1+(4+5)\\*14"));
        yaju.push_back(make_pair(127, "1-14\\*(5-14)"));
        yaju.push_back(make_pair(126, "1\\*(14-5)\\*14"));
        yaju.push_back(make_pair(125, "-1-14\\*(5-14)"));
        yaju.push_back(make_pair(124, "114+5+1+4"));
        yaju.push_back(make_pair(123, "114-5+14"));
        yaju.push_back(make_pair(122, "114+5-1+4"));
        yaju.push_back(make_pair(121, "11\\*(45-1)/4"));
        yaju.push_back(make_pair(120, "-(1+1)\\*4\\*5\\*(1-4)"));
        yaju.push_back(make_pair(118, "(1+1)\\*(45+14)"));
        yaju.push_back(make_pair(117, "(1-14)\\*(5-14)"));
        yaju.push_back(make_pair(116, "114+5+1-4"));
        yaju.push_back(make_pair(115, "114+5\\*1-4"));
        yaju.push_back(make_pair(114, "11\\*4+5\\*14"));
        yaju.push_back(make_pair(113, "114-5/1+4"));
        yaju.push_back(make_pair(112, "114-5-1+4"));
        yaju.push_back(make_pair(111, "11+4\\*5\\*(1+4)"));
        yaju.push_back(make_pair(110, "-(11-451)/4"));
        yaju.push_back(make_pair(107, "11-4\\*-(5+1)\\*4"));
        yaju.push_back(make_pair(106, "114-5+1-4"));
        yaju.push_back(make_pair(105, "114+5-14"));
        yaju.push_back(make_pair(104, "114-5-1-4"));
        yaju.push_back(make_pair(103, "11\\*(4+5)+1\\*4"));
        yaju.push_back(make_pair(102, "11\\*(4+5)-1+4"));
        yaju.push_back(make_pair(101, "1+1\\*4\\*5\\*(1+4)"));
        yaju.push_back(make_pair(100, "1\\*(1+4)\\*5\\*1\\*4"));
        yaju.push_back(make_pair(99, "11\\*4+51+4"));
        yaju.push_back(make_pair(98, "1+1+4\\*(5+1)\\*4"));
        yaju.push_back(make_pair(97, "1+1\\*4\\*(5+1)\\*4"));
        yaju.push_back(make_pair(96, "11\\*(4+5)+1-4"));
        yaju.push_back(make_pair(95, "-652188"));
        yaju.push_back(make_pair(94, "114-5/1\\*4"));
        yaju.push_back(make_pair(93, "(1+1)\\*45-1+4"));
        yaju.push_back(make_pair(92, "(1+1)\\*(45-1)+4"));
        yaju.push_back(make_pair(91, "11\\*4+51-4"));
        yaju.push_back(make_pair(90, "-114+51\\*4"));
        yaju.push_back(make_pair(89, "(1+14)\\*5+14"));
        yaju.push_back(make_pair(88, "1\\*14\\*(5+1)+4"));
        yaju.push_back(make_pair(87, "11+4\\*(5+14)"));
        yaju.push_back(make_pair(86, "(1+1)\\*45\\*1-4"));
        yaju.push_back(make_pair(85, "1+14+5\\*14"));
        yaju.push_back(make_pair(84, "1\\*14+5\\*14"));
        yaju.push_back(make_pair(83, "-1+14+5\\*14"));
        yaju.push_back(make_pair(82, "1+1+4\\*5/1\\*4"));
        yaju.push_back(make_pair(81, "1/1+4\\*5\\*1\\*4"));
        yaju.push_back(make_pair(80, "1-1+4\\*5\\*1\\*4"));
        yaju.push_back(make_pair(79, "1\\*-1+4\\*5/1\\*4"));
        yaju.push_back(make_pair(78, "(1+1)\\*4+5\\*14"));
        yaju.push_back(make_pair(77, "11-4+5\\*14"));
        yaju.push_back(make_pair(76, "1+1+4+5\\*14"));
        yaju.push_back(make_pair(75, "1+14\\*5\\*1+4"));
        yaju.push_back(make_pair(74, "1/1\\*4+5\\*14"));
        yaju.push_back(make_pair(73, "1\\*14\\*5-1+4"));
        yaju.push_back(make_pair(72, "-1-1+4+5\\*14"));
        yaju.push_back(make_pair(71, "(1+14)\\*5-1\\*4"));
        yaju.push_back(make_pair(70, "11+45+14"));
        yaju.push_back(make_pair(69, "1\\*14+51+4"));
        yaju.push_back(make_pair(68, "1+1-4+5\\*14"));
        yaju.push_back(make_pair(67, "1-1\\*4+5\\*14"));
        yaju.push_back(make_pair(66, "1\\*14\\*5-1\\*4"));
        yaju.push_back(make_pair(65, "1\\*14\\*5-1-4"));
        yaju.push_back(make_pair(64, "11\\*4+5\\*1\\*4"));
        yaju.push_back(make_pair(63, "11\\*4+5+14"));
        yaju.push_back(make_pair(62, "1+14+51-4"));
        yaju.push_back(make_pair(61, "1+1+45+14"));
        yaju.push_back(make_pair(60, "11+45\\*1+4"));
        yaju.push_back(make_pair(59, "114-51-4"));
        yaju.push_back(make_pair(58, "-1+1\\*45+14"));
        yaju.push_back(make_pair(57, "1+14\\*5-14"));
        yaju.push_back(make_pair(56, "1\\*14\\*5-14"));
        yaju.push_back(make_pair(55, "-1+14\\*5-14"));
        yaju.push_back(make_pair(54, "11-4+51-4"));
        yaju.push_back(make_pair(53, "11+45+1-4"));
        yaju.push_back(make_pair(52, "11+45/1-4"));
        yaju.push_back(make_pair(51, "11+45-1-4"));
        yaju.push_back(make_pair(50, "1+1\\*45/1+4"));
        yaju.push_back(make_pair(49, "1\\*1\\*45/1+4"));
        yaju.push_back(make_pair(48, "-11+45+14"));
        yaju.push_back(make_pair(47, "1/-1+45-1+4"));
        yaju.push_back(make_pair(46, "11\\*4+5+1-4"));
        yaju.push_back(make_pair(45, "11+4\\*5+14"));
        yaju.push_back(make_pair(44, "114-5\\*14"));
        yaju.push_back(make_pair(43, "1+1\\*45+1-4"));
        yaju.push_back(make_pair(42, "11+45-14"));
        yaju.push_back(make_pair(41, "1/1\\*45\\*1-4"));
        yaju.push_back(make_pair(40, "-11+4\\*51/4"));
        yaju.push_back(make_pair(39, "-11+45+1+4"));
        yaju.push_back(make_pair(38, "-11+45\\*1+4"));
        yaju.push_back(make_pair(37, "-11+45-1+4"));
        yaju.push_back(make_pair(36, "11+4\\*5+1+4"));
        yaju.push_back(make_pair(35, "11\\*4+5-14"));
        yaju.push_back(make_pair(34, "1-14+51-4"));
        yaju.push_back(make_pair(33, "1+1+45-14"));
        yaju.push_back(make_pair(32, "1\\*1+45-14"));
        yaju.push_back(make_pair(31, "1/1\\*45-14"));
        yaju.push_back(make_pair(30, "1\\*-1+45-14"));
        yaju.push_back(make_pair(29, "-11+45-1-4"));
        yaju.push_back(make_pair(28, "11+4\\*5+1-4"));
        yaju.push_back(make_pair(27, "11+4\\*5/1-4"));
        yaju.push_back(make_pair(26, "11-4+5+14"));
        yaju.push_back(make_pair(25, "11\\*4-5-14"));
        yaju.push_back(make_pair(24, "1+14-5+14"));
        yaju.push_back(make_pair(23, "1\\*14-5+14"));
        yaju.push_back(make_pair(22, "1\\*14+5-1+4"));
        yaju.push_back(make_pair(21, "-1-1+4+5+14"));
        yaju.push_back(make_pair(20, "-11+45-14"));
        yaju.push_back(make_pair(19, "1+1+4\\*5+1-4"));
        yaju.push_back(make_pair(18, "1+1+4\\*5\\*1-4"));
        yaju.push_back(make_pair(17, "11+4\\*5-14"));
        yaju.push_back(make_pair(16, "11-4-5+14"));
        yaju.push_back(make_pair(15, "1+14-5+1+4"));
        yaju.push_back(make_pair(14, "11+4-5/1+4"));
        yaju.push_back(make_pair(13, "1\\*14-5/1+4"));
        yaju.push_back(make_pair(12, "-11+4+5+14"));
        yaju.push_back(make_pair(11, "11\\*-4+51+4"));
        yaju.push_back(make_pair(10, "-11/4+51/4"));
        yaju.push_back(make_pair(9, "11-4+5+1-4"));
        yaju.push_back(make_pair(8, "11-4+5/1-4"));
        yaju.push_back(make_pair(7, "11-4+5-1-4"));
        yaju.push_back(make_pair(6, "1-14+5+14"));
        yaju.push_back(make_pair(5, "11-4\\*5+14"));
        yaju.push_back(make_pair(4, "-11-4+5+14"));
        yaju.push_back(make_pair(3, "11\\*-4+51-4"));
        yaju.push_back(make_pair(2, "-11+4-5+14"));
        yaju.push_back(make_pair(1, "11/(45-1)\\*4"));
    }

    string rep(int num) {
        return yjp(num) + "\n論證完畢（喜";
    }
};

class react_collector : public dpp::reaction_collector {
public:
    /* Collector will run for 20 seconds */
    react_collector(dpp::cluster* cl, dpp::snowflake id) : dpp::reaction_collector(cl, 20, id) { }

    /* Override the "completed" event and then output the number of collected reactions as a message. */
    virtual void completed(const std::vector<dpp::collected_reaction>& list) override {
        if (list.size()) {
            owner->message_create(dpp::message(list[0].react_channel->id, "I collected " + std::to_string(list.size()) + " reactions!"));
        }
        else {
            owner->message_create(dpp::message("... I got nothin'."));
        }
    }
};

class Decodejson {
//  json examples
/*
json example 1:
{
  "allowed_mentions":{"parse":[]},
  "attachments":[],
  "channel_id":"968693698206519356",
  "components":[],
  "content":"json",
  "embeds":[],
  "flags":0,
  "id":"1204067276119212072",
  "message_reference":
    {"channel_id":"968693698206519356",
    "fail_if_not_exists":false,
    "guild_id":"966718811216683109",
    "message_id":"1204023173826220093"},
  "nonce":"1204067278279147520",
  "tts":false,
  "type":19,
  "username":"grand_african"
}


json example 2:
"{
  "allowed_mentions":
    {
      "parse":[]
    },
   "attachments":
    [{
      "ephemeral":false,
      "filename":"mygo_1.gif",
      "id":"1204021998192431185",
      "size":382340,
      "url":"mygo_1.gif"
    },
    {
      "ephemeral":false,
      "filename":"P2.pdf",
      "id":"1204021998712258620",
      "size":4984081,
      "url":"P2.pdf"}
    ],
    "channel_id":"968693698206519356",
    "components":[],
    "content":"json\n@ショコラ @冠位非洲人 @我的美竹蘭怎麼可能是+9",
    "embeds":[],
    "flags":0,
    "id":"1204021999043747870",
    "nonce":"1204021986854961152",
    "tts":false,
    "type":0,
    "username":"grand_african"
}"
*/

private:
    string json_str, content;
    dpp::snowflake ch_id, ms_id, ref_ch_id, ref_ms_id;
    json ref;

    void setvalue(json parsed_json) {
        this->ch_id = snowflake(parsed_json["channel_id"]);
        this->ms_id = snowflake(parsed_json["id"]);
        this->content = parsed_json["content"];
        this->ref = parsed_json["message_reference"];
        if (!ref.empty()) {
            this->ref_ch_id = snowflake(ref["channel_id"]);
            this->ref_ms_id = snowflake(ref["message_id"]);
        }        
    }

public:

    Decodejson(dpp::message mes) {
        setvalue(mes.build_json(true, true));
    }

    Decodejson(json mes) {
        setvalue(mes);
    }

    Decodejson(string json_str) {
        setvalue(json::parse(json_str));
    }

    Decodejson() {
        ifstream jsonin("mesdata.json");
        if (jsonin.fail()) {
            cout << "No Json File.";
        }
        else {
            setvalue(json::parse(jsonin));
            //cout << data;
        }
    }

    dpp::snowflake getch() {
        return ch_id;
    }

    dpp::snowflake getms() {
        return ms_id;
    }

    dpp::snowflake getrefch() {
        return ref_ch_id;
    }

    dpp::snowflake getrefms() {
        return ref_ms_id;
    }
    /*
    dpp::snowflake getch(string s) {
        return to_string(ch_id);
    }

    dpp::snowflake getms(string s) {
        return to_string(ms_id);
    }*/

    string getcont() {
        return content;
    }
};
//只是看行數自爽用