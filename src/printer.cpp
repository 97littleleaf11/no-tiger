#include "printer.hpp"
#include <iostream>
namespace ntc {
Printer::Printer(std::ostream& _os) : os(_os), whitespace_cnt(0) {}

void Printer::indent(int cnt) { whitespace_cnt += cnt; }

void Printer::dedent(int cnt) { whitespace_cnt -= cnt; }

void Printer::output_space() { os << std::string(whitespace_cnt, ' '); }

void Printer::visit(TranslationUnit& translation_unit) {
  output_space();
  os << "<TranslationUnit>" << std::endl;
  indent();
  auto& decls = translation_unit.get_declarations();
  for (auto& decl : decls) {
    decl->accept(*this);
  }
  dedent();
  output_space();
  os << "</TranslationUnit>" << std::endl;
}

void Printer::visit(FunctionDefinition& function_definition) {
  output_space();
  os << "<FunctionDefinition>" << std::endl;
  indent();
  visit(*(function_definition.get_declaration_specifier()));
  visit(*(function_definition.get_identifier()));
  auto& parameter_list = function_definition.get_parameter_list();
  for (auto& parameter : parameter_list) {
    visit(*parameter);
  }
  visit(*(function_definition.get_compound_statement()));
  dedent();
  output_space();
  os << "</FunctionDefinition>" << std::endl;
}

void Printer::visit(DeclarationSpecifier& declaration_specifier) {
  output_space();
  os << "<DeclarationSpecifier>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</DeclarationSpecifier>" << std::endl;
}

void Printer::visit(Identifier& identifier) {
  output_space();
  os << "<Identifier";
  os << " name=" << identifier.get_name() << ">" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</Identifier>" << std::endl;
}

void Printer::visit(ParameterDeclaration& parameter_declaration) {
  output_space();
  os << "<ParameterDeclaration>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</ParameterDeclaration>" << std::endl;
}

void Printer::visit(TypeSpecifier& type_specifier) {
  output_space();
  os << "<TypeSpecifier>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</TypeSpecifier>" << std::endl;
}

void Printer::visit(CompoundStatement& compound_statement) {
  output_space();
  os << "<CompoundStatement>" << std::endl;
  indent();
  auto& statement_list = compound_statement.get_statement_list();
  for (auto& statement : statement_list) {
    statement->accept(*this);
  }
  dedent();
  output_space();
  os << "</CompoundStatement>" << std::endl;
}

void Printer::visit(ExpressionStatement& expression_statement) {
  output_space();
  os << "<ExpressionStatement>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</ExpressionStatement>" << std::endl;
}

void Printer::visit(ReturnStatement& return_statement) {
  output_space();
  os << "<ReturnStatement>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</ReturnStatement>" << std::endl;
}
void Printer::visit(BreakStatement& break_statement) {
  output_space();
  os << "<BreakStatement>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</BreakStatement>" << std::endl;
}
void Printer::visit(ContinueStatement& continue_statement) {
  output_space();
  os << "<ContinueStatement>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</ContinueStatement>" << std::endl;
}
void Printer::visit(IfStatement& if_statement) {
  output_space();
  os << "<IfStatement>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</IfStatement>" << std::endl;
}
void Printer::visit(WhileStatement& while_statement) {
  output_space();
  os << "<WhileStatement>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</WhileStatement>" << std::endl;
}
void Printer::visit(ForStatement& for_statement) {
  output_space();
  os << "<ForStatement>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</ForStatement>" << std::endl;
}

void Printer::visit(IntegerExpression& integer_expression) {
  output_space();
  os << "<IntegerExpression>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</IntegerExpression>" << std::endl;
}

void Printer::visit(FloatExpression& float_expression) {
  output_space();
  os << "<FloatExpression>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</FloatExpression>" << std::endl;
}

void Printer::visit(BooleanExpression& boolean_expression) {
  output_space();
  os << "<BooleanExpression>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</BooleanExpression>" << std::endl;
}

void Printer::visit(CharacterExpression& character_expression) {
  output_space();
  os << "<CharacterExpression>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</CharacterExpression>" << std::endl;
}

void Printer::visit(StringLiteralExpression& string_literal_expression) {
  output_space();
  os << "<StringLiteralExpression>" << std::endl;
  indent();

  dedent();
  output_space();
  os << "</StringLiteralExpression>" << std::endl;
}

}  // namespace ntc