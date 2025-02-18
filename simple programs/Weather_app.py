#weather app concept

import random

# Function to create weather data and write it to a file
def create_weather_data():
    weather = open("weather_data.txt", "w")

    # Lists of possible values for the weather data
    week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
    skies = ["sunny", "cloudy", "partly cloudy", "mostly cloudy", "foggy", "overcast", "clear", "stormy", "snowy", "windy"]
    wind_direction = ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]

    # Generate random weather data for each day of the week
    for day in week:
        temperature = random.randrange(40, 100)
        sky = random.choice(skies)
        chance_of_rain = random.randrange(0, 100,10)
        wind_speed = random.randrange(0, 30)
        direction = random.choice(wind_direction)

        # Write the generated data to the file
        weather.write(f" {day}, {temperature}, {sky}, {chance_of_rain}, {wind_speed}, {direction} \n")

    weather.close()

# Function to read weather data from a file and create a database (dictionary)
def create_database():
    weather = open("weather_data.txt", "r")
    weather_database = {}
    
    # Read each line from the file and seperate the data to be put into the dictionary
    for line in weather:
        day, temperature, sky, chance_of_rain, wind_speed, direction = line.strip().split(", ")
        weather_database[day] = {
            "temperature": int(temperature),
            "sky": sky,
            "chance_of_rain": int(chance_of_rain),
            "wind_speed": int(wind_speed),
            "wind_direction": direction
        }

    return weather_database

# Function to display weather data for a specific day
def display_data(database):
    day = input("What day would you like the weather for? | ex: Monday \n")

    if day in database:
        data = database[day]
        print(f"{day}:")
        print(f"  Temperature: {data['temperature']} F")
        print(f"  Sky: {data['sky']}")
        print(f"  Chance of Rain: {data['chance_of_rain']}%")
        print(f"  Wind Speed: {data['wind_speed']} mph")
        print(f"  Wind Direction: {data['wind_direction']} \n")
    else:
        print("That day is not in the database. Please try again. \n")

# Function to display weather data for all days
def display_all_data(database):
    for day in database:
        data = database[day]
        print(f"{day}:")
        print(f"  Temperature: {data['temperature']} F")
        print(f"  Sky: {data['sky']}")
        print(f"  Chance of Rain: {data['chance_of_rain']}%")
        print(f"  Wind Speed: {data['wind_speed']} mph")
        print(f"  Wind Direction: {data['wind_direction']} \n")

# Function to recive user interaction and have according options and actions
def user_interaction(w_database):
    user_input = input("Would you like to see the weather for a specific day, all days, or quit? | options: 1,2,3 \n")

    if(user_input) == "1":
        display_data(w_database)
        user_interaction(w_database) # calls again to continue interaction

    elif(user_input) == "2":
        display_all_data(w_database)
        user_interaction(w_database) # calls again to continue interaction

    else:
        print("-exiting-")

# Main function to create weather data, database, and start user interaction
def main():

    create_weather_data() # Create weather data and write to file
    weather_database = create_database() # Read data from file and create database

    user_interaction(weather_database)

main() # Call the main function to run the program