#include "sudoku.h"

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
                + to_string(res[2]) + "**張四星<:ark4:1107953907377901579>\n**" + to_string(res[1]) + "**張五星<:ark5:1107953865602637824>\n"
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
//只是看行數自爽用