#pragma once

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include <unordered_map>

/// \file ExpressionEvaluator.hpp
/// \brief Very simple and buggy set of utility functions to perform expression evaluation (with variables) on the CPU
///        Used to simplify the matrices before passing them to the shader. Also keeps track of the unknowns, e.g. variables
///        so that they're only calculated once within a draw loop.
/// \author Teemu Lindborg
/// \version 1.0
/// \date 22/01/17 Updated to NCCA Coding standard
/// Revision History :
/// Initial Version 11/11/16

/*
 * Please do not look at these!
 */
namespace hsitho {
  namespace Expressions
	{	
    ///
    /// \brief The Unknowns class, keeps track of the unknowns that have turned up during the expression evaluations
    ///
		class Unknowns {
			public:
        ///
        /// \brief instance Function the create and return a singleton of itself
        /// \return Returns an instance of the class
        ///
				static std::shared_ptr<Unknowns> instance()
				{
					if(m_instance == nullptr)
						m_instance.reset(new Unknowns);

					return m_instance;
				}

				~Unknowns() {}
        ///
        /// \brief setUnknown Checks if the same unknown has been seen before, if not appends it to a list of unknowns
        /// \param _val Unknown variable to check
        ///
				void setUnknown(std::string &_val) {
					if(_val.find("copyNum", 0) != std::string::npos || _val == "") {
						return;
					}
					if(m_unknowns.find(_val) == m_unknowns.end()) {
						for(auto &s : m_unknowns) {
							if(s.second == _val)
								return;
						}
						unsigned int a = m_unknowns.size();
						m_unknowns[_val] = 'a' + a;
					}
				}

        ///
        /// \brief getUnknowns
        /// \return Returns the unknowns
        ///
				std::unordered_map<std::string, std::string> getUnknowns() { return m_unknowns; }
				void clear() { m_unknowns.clear(); }

        ///
        /// \brief printUnknowns Prints the unknowns, for debugging purposes
        ///
				void printUnknowns() {
					for(auto &s : m_unknowns)
						std::cout << s.first << " " << s.second << "\n";
				}

			private:
        ///
        /// \brief Unknowns Hidden ctor as only one instance of this class should ever exist
        ///
				Unknowns() {}
        ///
        /// \brief Unknowns Deleted copy ctor to avoid problems
        /// \param _rhs
        ///
				Unknowns(const Unknowns &_rhs) = delete;
        ///
        /// \brief operator = Deleted assignment operator to avoid problems
        /// \param _rhs
        /// \return
        ///
				Unknowns& operator= (const Unknowns &_rhs) = delete;

        ///
        /// \brief m_instance Static pointer to the instance of the singleton
        ///
				static std::shared_ptr<Unknowns> m_instance;
        ///
        /// \brief m_unknowns Map of the unknowns encountered
        ///
				std::unordered_map<std::string, std::string> m_unknowns;
		};

    ///
    /// \brief parseExpression Removes/parses double operands
    /// \param _expression Expression to parse
    ///
		void parseExpression(std::string &_expression);
    ///
    /// \brief addSpaces Adds spaces between operands, used to then parse the expression
    /// \param _expression Expression to add spaces to
    /// \return Returns the expression with added spaces
    ///
    std::string addSpaces(const std::string &_expression);
    ///
    /// \brief evaluate Turns the expression to post fix notation and evaluates it
    /// \param _expression Expression to evaluate
    /// \param _prev Previous iteration of the evaluation, is used to recursively evaluate the expression till no change happens
    /// \param _copyNum Number of the copy of the node, used when the copy num is used as a variable
    /// \param _gen Which iteration of the evaluation is going on, only get the unknowns from the last one
    /// \return The parsed/evaluated expression
    ///
		std::string evaluate(const std::string &_expression, const std::string &_prev = "", const int &_copyNum = -1, const unsigned int &_gen = 0);
    ///
    /// \brief evaluatePostFix Evaluates the post fix notation generated by the evaluate function
    /// \param outputQueue Output queue holding the expression elements in post fix order
    /// \return Evaluated post fix notation
    ///
		std::string evaluatePostFix(std::vector<std::string> outputQueue);
    ///
    /// \brief getUnknowns Gets the unknowns in a format that can be used by the shader
    /// \return String containing the unknowns in a shader-readable format
    ///
		std::string getUnknowns();
    ///
    /// \brief checkSpaces Used to remove double spaces from the expressions
    /// \param lhs First character
    /// \param rhs Second character
    /// \return Whether the two consecutive characters are spaces
    ///
		bool checkSpaces(char lhs, char rhs);
    ///
    /// \brief setUnknowns Checks and sets the unknowns of the evaluated expression if needed
    /// \param _expression Expression to check the unknowns from
    ///
		void setUnknowns(const std::string &_expression);
    ///
    /// \brief replaceUnknowns Replaces the unknowns in the generated shader code with variables
    /// \param _expression Shader code to replace the unknowns from
    /// \return The shader code where every unknown is replaced by a predefined variable
    ///
		std::string replaceUnknowns(const std::string &_expression);
		void flushUnknowns();

    ///
    /// Utility-function to clamp a value between two values
    ///
    template<typename T>
    T clamp(const T _val, const T _v1, const T _v2)
    {
      if(_val < _v1)
        return _v1;
      else if(_val > _v2)
        return _v2;
      return _val;
		}
  }
}