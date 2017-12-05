#ifndef COMMAND_MODE_INPUT_PARSER_H
#define COMMAND_MODE_INPUT_PARSER_H

#include <memory>
#include <string>
#include <map>
#include "controller/InputParser.h"

namespace  vm {

class Command;
class SimpleCommand;
class DCommand;
class CCommand;
class AtCommand;
class YCommand;

class CommandModeInputParser : public InputParser{

	private:
		size_t numBuffer;
		size_t multiplier;

		std::map<int, Command*> commandMap;
		Command * current;

		void addEntries();


		std::unique_ptr<SimpleCommand> a;
		std::unique_ptr<SimpleCommand> b;
		std::unique_ptr<CCommand> c;
		std::unique_ptr<DCommand> d;
		std::unique_ptr<SimpleCommand> f;
		std::unique_ptr<SimpleCommand> h;
		std::unique_ptr<SimpleCommand> i;
		std::unique_ptr<SimpleCommand> j;
		std::unique_ptr<SimpleCommand> k;
		std::unique_ptr<SimpleCommand> l;
		std::unique_ptr<SimpleCommand> n;
		std::unique_ptr<SimpleCommand> o;
		std::unique_ptr<SimpleCommand> p;
		std::unique_ptr<SimpleCommand> q;
		std::unique_ptr<SimpleCommand> r;
		std::unique_ptr<SimpleCommand> s;
		std::unique_ptr<SimpleCommand> u;
		std::unique_ptr<SimpleCommand> w;
		std::unique_ptr<SimpleCommand> x;
		//std::unique_ptr<YCommand> y;

		std::unique_ptr<SimpleCommand> A;
		std::unique_ptr<SimpleCommand> F;
		std::unique_ptr<SimpleCommand> I;
		std::unique_ptr<SimpleCommand> J;
		std::unique_ptr<SimpleCommand> N;
		std::unique_ptr<SimpleCommand> O;
		std::unique_ptr<SimpleCommand> P;
		std::unique_ptr<SimpleCommand> R;
		std::unique_ptr<SimpleCommand> S;
		std::unique_ptr<SimpleCommand> X;
		std::unique_ptr<SimpleCommand> caret;
		std::unique_ptr<SimpleCommand> dollar;
		std::unique_ptr<SimpleCommand> dot;
		std::unique_ptr<SimpleCommand> semi;
		std::unique_ptr<SimpleCommand> slash;
		std::unique_ptr<SimpleCommand> colon;
		std::unique_ptr<SimpleCommand> question;
		std::unique_ptr<SimpleCommand> percent;
		std::unique_ptr<AtCommand> at;

	public:
		void reset();

		CommandModeInputParser();

		std::unique_ptr<Action> parseInput(KeyInput* in) override;

		~CommandModeInputParser() override;
};

}

#endif
