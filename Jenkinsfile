pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                bat "\"C:/Program Files/Microsoft Visual Studio/2022/Community/MSBuild/Current/Bin/MSBuild.exe\" Sample-lab4.slnx /t:Build /p:Configuration=Debug"
            }
        }
        stage('Test') {
            steps {
                bat "x64/Debug/Sample-lab4.exe --gtest_output=xml:test_report.xml"
            }
        }
    }
    post {
        always {
            junit 'test_report.xml'
        }
    }
}