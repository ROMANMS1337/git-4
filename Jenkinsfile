pipeline {
    agent any
    stages {
        stage('Restore') {
            steps {
                bat 'powershell -Command "[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest https://dist.nuget.org/win-x86-commandline/latest/nuget.exe -OutFile nuget.exe"'
                bat 'chcp 65001 && nuget.exe restore Sample-lab4.slnx'
            }
        }
        stage('Build') {
            steps {
                bat 'chcp 65001 && "C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" Sample-lab4.slnx /t:Rebuild /p:Configuration=Debug'
            }
        }
        stage('Test') {
            steps {
                bat 'chcp 65001 && "x64\\Debug\\Sample-lab4.exe" --gtest_output=xml:test_report.xml'
            }
        }
    }
    post {
        always {
            junit 'test_report.xml'
        }
    }
}
