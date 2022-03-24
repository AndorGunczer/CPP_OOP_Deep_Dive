/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:25:46 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 17:19:57 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm :public Form {
	private:
		std::string _target;
	
	public:
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

		std::string getTarget() const;
		void setTarget( std::string target );

		virtual void action() const;
};

# endif