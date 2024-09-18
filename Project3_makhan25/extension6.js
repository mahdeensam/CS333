/**
 * Extension 6: Enhanced compilable and runnable haiku and weather-themed poem generator.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * Date: 03/09/2024
 */

console.log("Waterville, Maine's skies");
console.log("Seasons paint a vivid tale");
console.log("Nature's grand disguise");

// Improved function to generate a random weather-themed poem with more variety
function generateWeatherPoem() {
  const templates = [
    {
      seasons: ["Spring", "Summer", "Autumn", "Winter"],
      adjectives: ["Gentle", "Radiant", "Crisp", "Frosty"],
      verbs: ["Dances", "Shimmers", "Paints", "Blankets"],
      objects: ["Flowers", "Sunbeams", "Leaves", "Snowflakes"],
    },
    // Additional templates can be added here for variety
  ];

  const template = templates[Math.floor(Math.random() * templates.length)];

  const randomSeason = selectRandom(template.seasons);
  const randomAdjective = selectRandom(template.adjectives);
  const randomVerb = selectRandom(template.verbs);
  const randomObject = selectRandom(template.objects);

  console.log(`A ${randomSeason} in Waterville:`);
  console.log(`\t${randomSeason} ${randomAdjective} and bright,`);
  console.log(`\t${randomVerb} the landscape with delight.`);
  console.log(`\t${randomObject} dance in the light.`);
}

// Helper function to select a random element from an array
function selectRandom(array) {
  return array[Math.floor(Math.random() * array.length)];
}

// Enhanced functionality to include customization and additional variety
generateWeatherPoem();
