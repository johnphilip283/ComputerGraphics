#version 330

// Take in our texture coordinate from our vertex shader
in vec2 texCoords;
// And our normal
in vec3 norm;
// And our fragment position for lighting
in vec3 fragPos;

// We always define a fragment color that we output.
out vec4 fragColor;

// Define our light(s)
struct PointLight {
    vec3 color;
    vec3 position;
    float ambientIntensity;
    float specularIntensity;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

// Maintain our uniforms.
uniform sampler2D tex;              // our primary texture
uniform mat4 view;                  // we need the view matrix for highlights
uniform PointLight pointLights[2];  // Our lights

void main() {

  fragColor = texture(tex, texCoords);
  vec3 diffuseColor = texture(tex, texCoords).rgb;
  vec3 light = vec3(0.0, 0.0, 0.0);

  for (int i = 0; i < 2; i += 1) {
      vec3 ambientLight = pointLights[i].ambientIntensity * pointLights[i].color;
      vec3 lightDir = normalize(pointLights[i].position - fragPos);

      float diffImpact = max(dot(norm, lightDir), 0.0);
      vec3 diffuseLight = diffImpact * pointLights[i].color;

      vec3 viewPos = vec3(0.0, 0.0, 0.0);
      vec3 viewDir = normalize(viewPos - fragPos);
      vec3 reflectDir = reflect(-lightDir, norm);

      float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
      vec3 specular = pointLights[i].specularIntensity * spec * pointLights[i].color;

      light += diffuseLight + ambientLight + specular;
  }
  
  fragColor = vec4(diffuseColor * light, 1.0);
  
}