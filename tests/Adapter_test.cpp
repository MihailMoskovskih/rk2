#include <gtest/gtest.h>

class Player{
public:
	virtual void attack()=0;
	virtual void defense()=0;
	Player(string name){
		this->name = name;
	}
	Player(){

	}
	virtual ~Player(){

	}
protected:
	string name;
};
class Forwards :public Player{
public:
	virtual void attack(){
		cout<<"Forward attack "<<name<<endl;
	}
	virtual void defense(){
		cout<<"Forward defense "<<name<<endl;
	}
	Forwards():Player(){

	}
	Forwards(string name_s){
		name = name_s;
	}
	virtual ~Forwards(){

	}
private:
	string name;
};
class Center: public Player{
public:
	virtual void attack(){
		cout<<"Center attack "<<name<<endl;
	}
	virtual void defense(){
		cout<<"Center defense "<<name<<endl;
	}
	Center(string name){
		this->name = name;
	}
	Center(){

	}
	virtual ~Center(){

	}
private:
	string name;
};
class ForeignCenter
{
public:

	void setName(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}
	void foreignCenterAttack(){
		cout<<"Foreign Center attack "<<name<<endl;
	}
	void foreignCenterDefense(){
		cout<<"Foreign Center defense "<<name<<endl;
	}
	ForeignCenter(string name){
		this->name = name;
	}
	ForeignCenter() {

	};

	~ForeignCenter() {

	};
	
private:
	string name;
};
//adapter
class Translator : public Player{
public:
	Translator(string name){
		fc = new ForeignCenter(name);
	}
	Translator(){

	}
	virtual void attack(){
		fc->foreignCenterAttack();
	}
	virtual void defense(){
		fc->foreignCenterDefense();
	}
	virtual ~Translator(){

	}
private:
	ForeignCenter* fc;
};

TEST(PlayerTest, ForwardsAttack) {
    Forwards f("John");
    testing::internal::CaptureStdout();
    f.attack();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Forward attack John\n", output);
}

TEST(PlayerTest, CenterDefense) {
    Center c("Jane");
    testing::internal::CaptureStdout();
    c.defense();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Center defense Jane\n", output);
}

TEST(PlayerTest, TranslatorAttackAndDefense) {
    Translator t("YaoMing");
    testing::internal::CaptureStdout();
    t.attack();
    t.defense();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Foreign Center attack YaoMing\nForeign Center defense YaoMing\n", output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
