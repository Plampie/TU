import json

object = {
    "name" : "Plamena",
    "age" : 19,
    "university" : "TU"
}

json_data = json.dumps(object)

print(f"Json data: {json_data}")