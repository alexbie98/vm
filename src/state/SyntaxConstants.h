#ifndef SYNTAX_CONSTANTS_H
#define SYNTAX_CONSTANTS_H

#include <vector>

namespace vm{

  namespace syntax{

    const int DoubleQuote = 1;
    const int SingleLineComment = 2;
    const int MultiLineComment = 3;
    const int Keyword = 4;
    const int ConditionalKeyword = 5;
    const int Identifier = 6;

    const std::vector<std::string> Keywords{
      "alignas",
      "alignof",
      "and",
      "and_eq",
      "asm",
      // atomic_cancel (TM TS)
      // atomic_commit (TM TS)
      // atomic_noexcept (TM TS)
      "auto(1)",
      "bitand",
      "bitor",
      "bool",
      "break",
      "case",
      "catch",
      "char",
      "char16_t",
      "char32_t",
      "class",
      "compl",
      //concept (since C++20)
      "const",
      "constexpr",
      "const_cast",
      "continue",
      //co_await (coroutines TS)
      //co_return (coroutines TS)
      //co_yield (coroutines TS)
      "decltype",
      "default",
      "delete",
      "do",
      "double",
      "dynamic_cast",
      "else",
      "enum",
      "explicit",
      "export",
      "extern",
      "false",
      "float",
      "for",
      "friend",
      "goto",
      "if",
      //import (modules TS)
      "inline",
      "int",
      "long",
      //module (modules TS)
      "mutable",
      "namespace",
      "new",
      "noexcept",
      "not",
      "not_eq",
      "nullptr",
      "operator",
      "or",
      "or_eq",
      "private",
      "protected",
      "public",
      "register",
      "reinterpret_cast",
      //requires (since C++20)
      "return",
      "short",
      "signed",
      "sizeof",
      "static",
      "static_assert",
      "static_cast",
      "struct",
      "switch",
      //synchronized (TM TS)
      "template",
      "this",
      "thread_local",
      "throw",
      "true",
      "try",
      "typedef",
      "typeid",
      "typename",
      "union",
      "unsigned",
      "using",
      "virtual",
      "void",
      "volatile",
      "wchar_t",
      "while",
      "xor",
      "xor_eq"
  };

}

}
#endif
