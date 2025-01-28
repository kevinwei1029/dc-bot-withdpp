#include "senpai.h"

//自定義函式
string error_reply(string tkusing, string tk0, string tk1) {
	if (tkusing == tk0)
		return "但......チョコラ不知道主人在說什麼欸？";
		//return "現在登入的是チョコラ";
	else if (tkusing == tk1)
		return "再鬧\n我就叫M3捅爆你屁眼";
		//return "現在登入的是凱爾希";
	else
		return "哇程式竟然抓不到是哪一隻機器人登入\n可以趕快回報給開發者這個bug";
}
string majong_number_reply(int size) {
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
bool canConvertToInt(const std::string& str) {
	try {
		stoi(str); // 嘗試轉換字串為整數
		return true;    // 成功轉換
	}
	catch (const std::invalid_argument&) {
		// 如果拋出 invalid_argument，表示字串不包含有效數字
		return false;
	}
	catch (const std::out_of_range&) {
		// 如果拋出 out_of_range，表示數字超出了 int 的範圍
		return false;
	}
}
/*
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
		command,                                // 指定命令列參數（使用存儲在字串內的命令）
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

}*/

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
		int* p = new int[10]();
		int num;
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
	string json_str, content, username, temp;
	dpp::snowflake ch_id, ms_id, ref_ch_id, ref_ms_id;
	json ref;

	void setvalue(json mes) {
		temp = mes["channel_id"];
		this->ch_id = snowflake(temp);
		temp = mes["id"];
		this->ms_id = snowflake(temp);
		this->content = mes["content"];
		this->username = mes["username"];
		this->ref = mes["message_reference"];
		if (!ref.empty()) {
			temp = ref["channel_id"];
			this->ref_ch_id = snowflake(temp);
			temp = ref["message_id"];
			this->ref_ms_id = snowflake(temp);
		}
	}

public:

	Decodejson(dpp::message mes) {
		setvalue(mes.build_json(true));
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

	string getusr() {
		return username;
	}
};

class MyCluster : public dpp::cluster {
public:
	
	MyCluster(const std::string &token) : dpp::cluster(token) {
		cout << "ckp2\n";
	}

	~MyCluster(){
		cout << "ckp4\n";
	}

	void botout(dpp::snowflake id, const std::string s) {
		cout << "ckp3-1\n";
		message_create(dpp::message(id, s));
	};

	void botout(const std::string s) {
		cout << "ckp3-2\n";
		message_create(dpp::message(968693698206519356, s));
	};

};

class Kahoot
{
private:
	struct Data
	{
		string name;
		string uid;
		float score;
		string ans[100];
		Data(string n, string id) : name(n), uid(id), score(0) {}
	};
	vector<Data> players;
	string reply = "", correctans = "";
	int quenum = 0, weight = 0;
	
	enum status
	{
		joining,
		playing,
		checking,
		end
	};
	int sta = joining;

	ofstream resout;

	void toUpperCase(std::string& str) {
		for (char& c : str) {
			c = (c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c; // 手動轉換小寫到大寫
		}
	}

	bool parseSetque(const std::string& input) {
		// 定義正則表達式：匹配 "SETQUE 題號 分數"
		regex pattern(R"(SETQUE\s+(\d+)\s+(\d+))");
		smatch match;

		// 使用正則表達式進行匹配
		if (regex_match(input, match, pattern)) {
			// 提取題號和分數
			if (stoi(match[1]) <= 0 || stoi(match[2]) <= 0) {
				reply = "題號或配分不能為負！請重新設定。\n";
				return false;
			}
			else if (quenum >= stoi(match[1])) {
				reply = "題號不能小於前一題！請重新設定。\n";
				return false;
			}
			else if (stoi(match[1]) >= 100) {
				reply = "題號不能大於100！請重新設定\n";
				return false;
			}
			quenum = stoi(match[1]); // 第一個捕獲組 (題號)
			weight = stoi(match[2]); // 第二個捕獲組 (分數)
			return true;
		}

		// 格式不匹配
		reply = "請依 `SETQUE 題號 分數` 格式輸入。\n";
		return false;
	}

	string floatToString(float value) {
		string result = to_string(value);
		// 移除尾隨零
		result.erase(result.find_last_not_of('0') + 1, string::npos);
		// 如果最後是小數點，也移除
		if (result.back() == '.') {
			result.pop_back();
		}
		return result;
	}

public:

	int getsta()
	{
		return sta;
	}

	string getuid(string name)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].name == name) return players[i].uid;
		}
		return "";
	}

	string getuid(int num)
	{
		if (num > players.size()) return "";
		return players[num - 1].uid;
	}

	string join(string name, string uid)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].name == name)
			{
				reply = " 已在遊戲內。編號：" + to_string(i + 1) + '\n';
				return reply;
			}
		}
		Data newplayer(name, uid);
		players.push_back(newplayer);
		reply = " 成功加入遊戲。編號：" + to_string(players.size()) + '\n';
		return reply;
	}

	string setque(string command)
	{
		if (parseSetque(command)) {
			reply = "題號：" + to_string(quenum) + "、配分：" + to_string(weight) + "分。\n請開始作答。\n";
			sta = playing;
			return reply;
		}
		else {
			return reply;
		}
	}

	string answering(string name, string ans)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].name == name)
			{
				if (players[i].ans[quenum] != "") reply = " 更改了他的答案。\n";
				else reply = " 已作答。\n";
				toUpperCase(ans);
				players[i].ans[quenum] = ans;
				return reply;
			}
		}
		reply = " 尚未進入遊戲中。\n";
		return reply;
	}

	string checkans(string ans)
	{
		sta = checking;
		correctans = ans;
		resout.open("result.txt");
		int add = 0;
		reply = "正確答案是：" + ans + "。\n";
		for (int i = 0; i < players.size(); i++)
		{
			resout << setw(20) << players[i].name << " " << setw(20) << players[i].uid << " " << setw(3) << players[i].score << " ";
			for (int j = 0; j <= quenum; j++)
			{
				resout << '|' << setw(3) << players[i].ans[j] << "|";
			}

			if (players[i].ans[quenum] == ans) add = weight;
			else add = 0;
			players[i].score += add;
			reply += players[i].name + " got " + to_string(add) + " points in this question and has " + floatToString(players[i].score) + " points totally.\n";
		}
		resout.close();
		return reply;
	}

	string addpoint(int num, int points) {
		if (players[num - 1].score + points > 0) {
			players[num - 1].score += points;
			return " add " + to_string(points) + " points to ";
		}
		else {
			return " can't have negative points to ";
		}
	}

	string finalscore()
	{
		sta = end;
		resout.open("finalresult.txt");
		sort(players.begin(), players.end(), [](Data a, Data b) {return a.score > b.score; });
		reply = "The final score is:\n";
		for (int i = 0; i < players.size(); i++)
		{
			reply += players[i].name + " got " + to_string(players[i].score) + " points.\n";
		}
		resout << reply;
		resout.close();
		return reply;
	}
};
//只是看行數自爽用