module.exports = function (grunt) {
    grunt.loadNpmTasks('grunt-contrib-less');
    grunt.loadNpmTasks('grunt-contrib-watch');

    grunt.initConfig({
        watch: {
            files: "less/*.less",
            tasks: ["less"]
        },
        less: {
            development: {
                options: {
                    paths: ["less/"]
                },
                files: {
                    "css/style.css": "less/style.less"
                }
            }
        }
    });
    grunt.registerTask('default', ['watch']);
};