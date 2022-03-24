/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:25:46 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 17:19:50 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm :public Form {
	private:
		std::string _target;
	
	public:
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

		std::string getTarget() const;
		void setTarget( std::string target );
		
		virtual void action() const;
};

# endif