/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:41:42 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 16:21:09 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int	main( void )
{
	Data* data = new Data(42);
	uintptr_t serializedData = Serializer::serialize(data);
	Data* deserializedData = Serializer::deserialize(serializedData);

	std::cout << "Data : " << data->getValue() << std::endl;
	std::cout << "Serialized Data : " << serializedData << std::endl;
	std::cout << "Deserialized Data : " << deserializedData->getValue() << std::endl;

	std::cout << "Address of data: " << data << std::endl;
	std::cout << "Address of serializedData: " << &serializedData << std::endl;
	std::cout << "Address of deserializedData: " << deserializedData << std::endl;

	deserializedData->setValue(21);
	std::cout << "New Deserialized Data : " << deserializedData->getValue() << std::endl;
	delete data;

	return 0;
}
