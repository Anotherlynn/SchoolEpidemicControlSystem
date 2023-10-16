# SchoolEpidemicControlSystem

Efficiently manage and track real-time epidemic/COVID-19-related data within school and hospital maps in Beijing. Focus on ensuring student safety during health crises by building the database, and searching the shortest path using C++ and Shortest Path Faster Algorithm (SPFA).


## Table of Contents
- [Introduction](#introduction)
- [Inspiration](#inspiration)
- [System Structure](#system-structure)
- [Data Authenticity](#data-authenticity)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contribution](#contribution)

## Introduction
This is a system designed to manage epidemic-related data using real-time map. The focus is on tracking data related to certain communities and the specific health conditions of people (users). The app ensures accurate tracking and effective prevention during epidemic outbreaks.

## Inspiration
The motivation behind this project stems from a real-world situation where a sudden epidemic outbreak occurred at the Xinfadi wholesale market in Beijing. Multiple residential areas, including schools, were affected in its vicinity.

## System Structure
![deploy](https://github.com/Anotherlynn/SchoolEpidemicControlSystem/assets/74956197/8acaeab4-f474-463e-a4e6-f898376442c5)
- **School**: Contains overarching details about different schools.
- **Grade**: Information related to various grades within the schools.
- **Class**: Details about specific classes within grades.
- **Healthy Students**: List and details of students who are currently healthy.
- **In Quarantine Students**: Information on students who are under quarantine.
- **Affected Students**: Data related to students who have been confirmed to be affected by the epidemic.
- **Observation - Affected Cases**: Students who are under observation and have been confirmed.
- **Observation - Suspicious Cases**: Students who are under observation due to suspicion of infection.
- **Observation - Pending Cases**: Students who are under observation as they were in close contact with confirmed cases.

## Data Authenticity
The addresses and distances used in this project are derived from real-world data of Beijing, China, ensuring the system's accuracy and relevance.

## Getting Started

### Prerequisites
Before you begin, ensure you have met the following requirements:
- Necessary software (e.g., Python 3.7, PostgreSQL).
- Required libraries and tools (e.g., Django, ReactJS).
- Any other dependencies.

### Installation
To install and set up the project, follow these steps:
```bash
git clone https://github.com/Anotherlynn/SchoolEpidemicControlSystem.git)https://github.com/Anotherlynn/SchoolEpidemicControlSystem.git
cd SchoolEpidemicControlSystem
```
