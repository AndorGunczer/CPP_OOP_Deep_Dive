/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:19:06 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 10:42:10 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm :public Form {
	private:
		std::string _target;
	
	public:
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

		std::string getTarget() const;
		void setTarget( std::string target );

};

# endif